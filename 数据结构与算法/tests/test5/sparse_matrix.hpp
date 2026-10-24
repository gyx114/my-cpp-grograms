#ifndef SPARSE_MATRIX_HPP
#define SPARSE_MATRIX_HPP

#include "../my_stl/vector.hpp"
#include "../my_stl/sorts.hpp"
#include <utility>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <limits>

namespace gyx
{
    template <typename T>
    class sparse_matrix
    {
    public:
        struct MatrixTerm // 非零元素及其位置
        {
            size_t row;
            size_t col;
            T val;

            MatrixTerm(long long row_, long long col_, const T &val_ = 0) : row(static_cast<size_t>(row_)), col(static_cast<size_t>(col_)), val(val_)
            {
                if (row_ < 0 || col_ < 0)
                {
                    throw BadIndex(row_, col_);
                }
            }
            MatrixTerm(long long row_, long long col_, T &&val_) : row(static_cast<size_t>(row_)), col(static_cast<size_t>(col_)), val(std::move(val_))
            {
                if (row_ < 0 || col_ < 0)
                {
                    throw BadIndex(row_, col_);
                }
            }

            MatrixTerm(const MatrixTerm &other) : row(other.row), col(other.col), val(other.val) {}

            MatrixTerm(MatrixTerm &&other) noexcept : row(other.row), col(other.col), val(std::move(other.val))
            {
                other.row = 0;
                other.col = 0;
            }

            MatrixTerm &operator=(const MatrixTerm &other)
            {
                if (this != &other)
                {
                    row = other.row;
                    col = other.col;
                    val = other.val;
                }
                return *this;
            }

            MatrixTerm &operator=(MatrixTerm &&other) noexcept
            {
                if (this != &other)
                {
                    row = other.row;
                    col = other.col;
                    val = std::move(other.val);

                    other.row = 0;
                    other.col = 0;
                }
                return *this;
            }

            void move_to_next(size_t width)
            {
                if (width == 0)
                {
                    throw SizeIllegal();
                }
                if (col == width - 1)
                {
                    col = 0;
                    row++;
                }
                else
                {
                    col++;
                }
            }
        };

        class BadIndex : public std::out_of_range // 越界访问异常
        {
        private:
            long long row_, col_;

        public:
            long long row() const { return row_; }
            long long col() const { return col_; }

            BadIndex(long long r, long long c) : std::out_of_range("The index you are inquiring is out of range!"), row_(r), col_(c) {}
        };

        struct SizeUnmatch : public std::invalid_argument // 尺寸不匹配
        {
            SizeUnmatch() : std::invalid_argument("the other matrix\'s size is illegal!") {};
        };

        struct SizeIllegal : public std::invalid_argument // 尺寸不合法
        {
            SizeIllegal() : std::invalid_argument("the size you expect is illegal!") {};
        };

        size_t row_cnt() const noexcept { return row_cnt_; }
        size_t col_cnt() const noexcept { return col_cnt_; }

        ~sparse_matrix() = default;

        sparse_matrix(size_t r = 0, size_t c = 0) : row_cnt_(r), col_cnt_(c) {}

        sparse_matrix(const sparse_matrix &other) : row_cnt_(other.row_cnt_), col_cnt_(other.col_cnt_), data_(other.data_) {}
        sparse_matrix(sparse_matrix &&other) noexcept : row_cnt_(other.row_cnt_), col_cnt_(other.col_cnt_), data_(std::move(other.data_)) {}

        sparse_matrix &operator=(const sparse_matrix &other)
        {
            if (this != &other)
            {
                row_cnt_ = other.row_cnt_;
                col_cnt_ = other.col_cnt_;
                data_ = other.data_;
            }
            return *this;
        }
        sparse_matrix &operator=(sparse_matrix &&other) noexcept
        {
            if (this != &other)
            {
                row_cnt_ = other.row_cnt_;
                col_cnt_ = other.col_cnt_;
                data_ = std::move(other.data_);
            }
            return *this;
        }

        // 重置，读取完整矩阵
        void reset(long long r_cnt, long long c_cnt)
        {
            if (r_cnt < 0 || c_cnt < 0)
            {
                throw SizeIllegal();
            }

            using ull = unsigned long long;
            if (static_cast<ull>(r_cnt) > std::numeric_limits<size_t>::max() ||
                static_cast<ull>(c_cnt) > std::numeric_limits<size_t>::max())
                throw SizeIllegal();

            data_.clear();
            row_cnt_ = static_cast<size_t>(r_cnt);
            col_cnt_ = static_cast<size_t>(c_cnt);
            for (size_t i = 0; i < r_cnt; i++)
            {
                for (size_t j = 0; j < c_cnt; j++)
                {
                    T tmp;
                    std::cin >> tmp;
                    if (tmp)
                    {
                        data_.emplace_back(i, j, std::move(tmp));
                    }
                }
            }
        }

        sparse_matrix operator*(const T &c) const // 数乘矩阵
        {
            if (!c)
            {
                return sparse_matrix(row_cnt_, col_cnt_);
            }
            sparse_matrix res = *this;
            for (MatrixTerm &elem : res.data_)
            {
                elem.val *= c;
            }
            return res;
        }

        sparse_matrix &operator*=(const T &c)
        {
            if (!c)
            {
                data_.clear();
            }
            else
            {
                for (MatrixTerm &elem : data_)
                {
                    elem.val *= c;
                }
            }
            return *this;
        }

        T get(long long i, long long j) const
        {
            if (i < 0 || j < 0 || i >= row_cnt_ || j >= col_cnt_)
            {
                throw BadIndex(i, j);
            }
            MatrixTerm tmp(i, j);
            auto it = data_.lower_bound(data_.begin(), data_.end(), tmp, lexicographical_oder_less());
            if (it == data_.end() || (*it).row != i || (*it).col != j)
            {
                return static_cast<T>(0);
            }

            return (*it).val;
        }

        void set(long long i, long long j, const T &v)
        {
            if (i < 0 || j < 0 || i >= row_cnt_ || j >= col_cnt_)
            {
                throw BadIndex(i, j);
            }
            MatrixTerm tmp(i, j, v);
            typename vector<MatrixTerm>::iterator it = data_.lower_bound(data_.begin(), data_.end(), tmp, lexicographical_oder_less());

            if (it == data_.end() || (*it).row != i || (*it).col != j) // 原本没记录
            {
                if (v) // 新值非0才插入
                {
                    data_.insert(it, std::move(tmp));
                }
            }
            else // 有记录
            {
                if (v) // 新值非0，修改
                {
                    *it = std::move(tmp);
                }
                else // 新值为0，删除
                {
                    data_.erase(it);
                }
            }
        }

        void add_at(long long i, long long j, const T &v) // 在(i,j)处加v
        {
            if (i < 0 || j < 0 || i >= row_cnt_ || j >= col_cnt_)
            {
                throw BadIndex(i, j);
            }
            if (!v)
            {
                return;
            }
            MatrixTerm tmp(i, j, v);
            auto it = data_.lower_bound(data_.begin(), data_.end(), tmp, lexicographical_oder_less());
            if (it == data_.end() || (*it).row != i || (*it).col != j) // 要插入
            {
                data_.insert(it, std::move(tmp));
            }
            else // 要修改
            {
                if (it->val + v)
                {
                    it->val += v;
                }
                else
                {
                    data_.erase(it);
                }
            }
        }

        sparse_matrix operator*(const sparse_matrix &other) const // 矩阵相乘
        {
            if (col_cnt_ != other.row_cnt_)
            {
                throw SizeUnmatch();
            }
            sparse_matrix ret(row_cnt_, other.col_cnt_);

            vector<int> other_row_start(other.row_cnt_ + 1); // other的行索引数组，第i行在data_中的下标范围为[ other_row_start[i] , other_row_start[i+1] )

            for (auto &item2 : other.data_)
            {
                other_row_start[item2.row + 1]++; // 先记录每一行有几个元素
            }
            for (int i = 1; i < other.row_cnt_ + 1; i++)
            {
                other_row_start[i] += other_row_start[i - 1]; // 求前缀和之后就是行索引
            }

            vector<T> temp(other.col_cnt_); // 临时矩阵，缓存结果
            vector<int> used;               // temp矩阵的哪些下标被用过
            used.reserve(other.col_cnt_);

            sorter ster;
            int last_row = 0;
            for (auto &item1 : data_)
            {
                auto r1 = item1.row;
                auto c1 = item1.col;

                if (r1 != last_row) // 换行了，要写入结果
                {
                    ster.quick_sort(used.begin(), used.end());
                    int last_idx = -1;
                    for (auto idx : used)
                    {
                        if (idx != last_idx)
                        {
                            if (temp[idx])
                            {
                                ret.data_.emplace_back(last_row, idx, temp[idx]);
                                temp[idx] = 0; // 写完结果顺手清零
                            }
                            last_idx = idx;
                        }
                    }
                    last_row = r1;

                    // 然后清空
                    used.clear();
                }

                for (int i = other_row_start[c1]; i < other_row_start[c1 + 1]; i++)
                {
                    auto c2 = other.data_[i].col;
                    T v = item1.val * other.data_[i].val;
                    if (!temp[c2])
                    {
                        used.push_back(c2);
                    }
                    temp[c2] += v;
                }
            }
            // 最后一行写入结果
            ster.quick_sort(used.begin(), used.end());
            int last_idx = -1;
            for (auto idx : used)
            {
                if (idx != last_idx)
                {
                    if (temp[idx])
                    {
                        ret.data_.emplace_back(last_row, idx, temp[idx]);
                        temp[idx] = 0; // 写完结果顺手清零
                    }
                    last_idx = idx;
                }
            }

            return ret;
        }

        sparse_matrix &operator*=(const sparse_matrix &other)
        {
            return operator=(move(operator*(other)));
        }

        sparse_matrix operator+(const sparse_matrix &other) const // 矩阵加法
        {
            if (other.row_cnt_ != row_cnt_ || other.col_cnt_ != col_cnt_)
            {
                throw SizeUnmatch();
            }
            sparse_matrix ret(row_cnt_, col_cnt_);
            auto it1 = data_.begin();
            auto it2 = other.data_.begin();
            auto lss = lexicographical_oder_less();
            while (it1 != data_.end() && it2 != other.data_.end())
            {
                if (lss(*it1, *it2))
                {
                    ret.data_.emplace_back(*it1);
                    it1++;
                }
                else if (lss(*it2, *it1))
                {
                    ret.data_.emplace_back(*it2);
                    it2++;
                }
                else
                {
                    T val = (*it2).val + (*it1).val;
                    if (val)
                    {
                        ret.data_.emplace_back((*it1).row, (*it1).col, val);
                    }
                    it1++;
                    it2++;
                }
            }
            while (it1 != data_.end())
            {
                ret.data_.emplace_back(*it1);
                it1++;
            }
            while (it2 != other.data_.end())
            {
                ret.data_.emplace_back(*it2);
                it2++;
            }

            return ret;
        }

        sparse_matrix &operator+=(const sparse_matrix &other)
        {
            return operator=(move(operator+(other)));
        }

        void rotate()
        {
            to_csr();
            for (auto &item : data_)
            {
                swap(item.row, item.col);
            }
            swap(row_cnt_, col_cnt_);
        }

        void push_back_to_the_none_zero_table(int r, int c, const T &v)
        {
            data_.emplace_back(r, c, v);
        }

        template <typename Y>
        friend std::ostream &operator<<(std::ostream &os, const sparse_matrix<Y> &obj);

    private:
        size_t row_cnt_;
        size_t col_cnt_;
        vector<MatrixTerm> data_;

        void to_csr() // 记录变成列主顺序
        {
            sorter ster;
            ster.quick_sort(data_.begin(), data_.end(), csr_sorter_less());
        }

        struct lexicographical_oder_less // 行主字典序的less
        {
            bool operator()(const MatrixTerm &a, const MatrixTerm &b) const
            {
                return (a.row < b.row) || (a.row == b.row && a.col < b.col);
            }
        };
        struct csr_sorter_less // 列主排序时的less,即列主字典序的less
        {
            bool operator()(const MatrixTerm &a, const MatrixTerm &b) const
            {
                return (a.col < b.col) || (a.col == b.col && a.row < b.row);
            }
        };
    };

    template <typename T>
    inline std::ostream &operator<<(std::ostream &os, const sparse_matrix<T> &obj)
    {
        os << obj.row_cnt() << " " << obj.col_cnt() << "\n";
        if (obj.row_cnt() > 0 && obj.col_cnt() > 0)
        {
            typename sparse_matrix<T>::MatrixTerm tmp(0, 0);
            typename sparse_matrix<T>::MatrixTerm end(obj.row_cnt() - 1, obj.col_cnt());
            typename sparse_matrix<T>::lexicographical_oder_less lss;
            for (auto &item : obj.data_)
            {
                while (lss(tmp, item)) // 输出夹在中间的0
                {
                    os << static_cast<T>(0);
                    if (tmp.col == obj.col_cnt() - 1)
                    {
                        os << '\n';
                    }
                    else
                    {
                        os << ' ';
                    }
                    tmp.move_to_next(obj.col_cnt());
                }

                os << item.val; // 输出非0
                if (tmp.col == obj.col_cnt() - 1)
                {
                    os << '\n';
                }
                else
                {
                    os << ' ';
                }
                tmp.move_to_next(obj.col_cnt());
            }

            while (lss(tmp, end)) // 输出尾巴的0
            {
                os << static_cast<T>(0);
                if (tmp.col == obj.col_cnt() - 1)
                {
                    os << '\n';
                }
                else
                {
                    os << ' ';
                }
                tmp.move_to_next(obj.col_cnt());
            }
        }
        return os;
    }

} // namespace gyx

#endif
