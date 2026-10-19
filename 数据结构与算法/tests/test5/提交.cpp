#ifndef GYX_MY_STL_VECTOR_HPP
#define GYX_MY_STL_VECTOR_HPP

#include <cstddef>
#include <stdexcept>
#include <utility> // std::move / std::forward / std::move_if_noexcept
#include <new>     // placement new / ::operator new
#ifndef GYX_MY_STL_UTILITY_HPP
#define GYX_MY_STL_UTILITY_HPP

#include <utility>

namespace gyx
{
    // 去引用
    template <typename T>
    struct RemoveRef
    {
        using type = T;
    };

    template <typename T>
    struct RemoveRef<T &>
    {
        using type = T;
    };

    template <typename T>
    struct RemoveRef<T &&>
    {
        using type = T;
    };

    template <typename T>
    constexpr typename RemoveRef<T>::type &&move(T &&val) noexcept
    {
        return static_cast<typename RemoveRef<T>::type &&>(val);
    }

    template <typename T>
    void swap(T &a, T &b)
    {
        T tmp = move(a);
        a = move(b);
        b = move(tmp);
    }

    template <typename T = void>
    struct less
    {
        bool operator()(const T &a, const T &b) const
        {
            return a < b;
        }
    };

    // 对void版本特化
    template <>
    struct less<void>
    {
        template <typename T, typename U>
        constexpr auto operator()(T &&a, U &&b) const -> decltype(std::forward<T>(a) < std::forward<U>(b))
        {
            return std::forward<T>(a) < std::forward<U>(b);
        }
    };

    template <typename T = void>
    struct greater
    {
        bool operator()(const T &a, const T &b) const
        {
            return a > b;
        }
    };

    // 对void版本特化
    template <>
    struct greater<void>
    {
        template <typename T, typename U>
        constexpr auto operator()(T &&a, U &&b) const -> decltype(std::forward<T>(a) > std::forward<U>(b))
        {
            return std::forward<T>(a) > std::forward<U>(b);
        }
    };

} // namespace gyx

#endif

#include <initializer_list>

namespace gyx
{
    template <typename T>
    class vector
    {
    public:
        // typedef
        using value_type = T;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t; // 迭代器差值
        using pointer = T *;
        using const_pointer = const T *;
        using reference = T &;
        using const_reference = const T &;

    private:
        T *arr_ = nullptr;
        size_type size_ = 0;
        size_type capacity_ = 0;

        // 清理器
        // 将堆上分配的内存交给一个栈上的清理器
        // 如果抛异常，析构清理器时会顺带析构元素+释放内存
        struct construction_guard
        {
            T *data;
            size_type count;

            construction_guard(T *data_, size_type count_) : data(data_), count(count_) {}
            ~construction_guard()
            {
                for (size_type i = 0; i < count; i++)
                {
                    (data + i)->~T(); // 逐个析构
                }
                ::operator delete(data); // 释放内存
            }

            void release() // 取消对内存的管理
            {
                data = nullptr;
                count = 0;
                // 放弃资源所有权，避免construction_guard析构时再把正确的data给释放了
            }
        };

        void reallocate(size_type n) // 扩容
        {
            T *new_arr = static_cast<T *>(::operator new(n * sizeof(T))); // 分配内存而不初始化
            // 类型必须是T*，方便指针偏移，对单个位置赋值

            construction_guard guard(new_arr, 0);

            // 移动或者拷贝
            for (size_type i = 0; i < size_; i++)
            {
                new (new_arr + i) T(std::move_if_noexcept(arr_[i]));
                guard.count++;
            }

            // 全构造成功,安全了,release
            guard.release();

            // 销毁旧元素
            for (size_type i = 0; i < size_; i++)
            {
                arr_[i].~T(); // 对每个对象析构，让内存变为裸内存
            }
            ::operator delete(arr_);
            arr_ = new_arr;
            capacity_ = n;
        }

    public:
        // const迭代器
        class const_iterator
        {
        private:
            T *ptr = nullptr;

        public:
            explicit const_iterator(T *p) : ptr(p) {}
            const_iterator(const const_iterator &other) : ptr(other.ptr) {}

            ~const_iterator() {}

            const_iterator &operator=(const const_iterator &that)
            {
                if (this != &that)
                {
                    ptr = that.ptr;
                }
                return *this;
            }

            const T &operator*() const
            {
                return *ptr;
            }

            const T *operator->() const
            {
                return ptr;
            }

            const_iterator &operator++()
            {
                ptr++;
                return *this;
            }

            const_iterator operator++(int)
            {
                const_iterator tmp = *this;
                ptr++;
                return tmp;
            }

            const_iterator operator+(difference_type n) const
            {
                return const_iterator(ptr + n);
            }

            const_iterator &operator+=(difference_type n)
            {
                ptr += n;
                return *this;
            }

            const_iterator &operator--()
            {
                ptr--;
                return *this;
            }

            const_iterator operator--(int)
            {
                const_iterator tmp = *this;
                ptr--;
                return tmp;
            }

            const_iterator operator-(difference_type n) const
            {
                return const_iterator(ptr - n);
            }

            difference_type operator-(const const_iterator &rht) const
            {
                return ptr - rht.ptr;
            }

            const_iterator &operator-=(difference_type n)
            {
                ptr -= n;
                return *this;
            }

            bool operator==(const const_iterator &other) const
            {
                return this->ptr == other.ptr;
            }

            bool operator!=(const const_iterator &other) const
            {
                return this->ptr != other.ptr;
            }

            bool operator<(const const_iterator &other) const
            {
                return this->ptr < other.ptr;
            }

            bool operator>(const const_iterator &other) const
            {
                return this->ptr > other.ptr;
            }

            bool operator<=(const const_iterator &other) const
            {
                return this->ptr <= other.ptr;
            }

            bool operator>=(const const_iterator &other) const
            {
                return this->ptr >= other.ptr;
            }
        };

        // 迭代器
        class iterator
        {
        private:
            T *ptr = nullptr;

        public:
            explicit iterator(T *p) : ptr(p) {}
            iterator(const iterator &other) : ptr(other.ptr) {}

            ~iterator() {}

            iterator &operator=(const iterator &that)
            {
                if (this != &that)
                {
                    ptr = that.ptr;
                }
                return *this;
            }

            T &operator*() const
            {
                return *ptr;
            }

            T *operator->() const
            {
                return ptr;
            }

            iterator &operator++()
            {
                ptr++;
                return *this;
            }

            iterator operator++(int)
            {
                iterator tmp = *this;
                ptr++;
                return tmp;
            }

            iterator operator+(difference_type n) const
            {
                return iterator(ptr + n);
            }

            iterator &operator+=(difference_type n)
            {
                ptr += n;
                return *this;
            }

            iterator &operator--()
            {
                ptr--;
                return *this;
            }

            iterator operator--(int)
            {
                iterator tmp = *this;
                ptr--;
                return tmp;
            }

            iterator operator-(difference_type n) const
            {
                if (!ptr)
                {
                    return iterator(ptr);
                }
                return iterator(ptr - n);
            }

            difference_type operator-(const iterator &rht) const
            {
                if (ptr == rht.ptr)
                {
                    return 0;
                }
                return ptr - rht.ptr;
            }

            iterator &operator-=(difference_type n)
            {
                if (ptr)
                {
                    ptr -= n;
                }
                return *this;
            }

            bool operator==(const iterator &other) const
            {
                return this->ptr == other.ptr;
            }

            bool operator!=(const iterator &other) const
            {
                return this->ptr != other.ptr;
            }

            bool operator<(const iterator &other) const
            {
                return this->ptr < other.ptr;
            }

            bool operator>(const iterator &other) const
            {
                return this->ptr > other.ptr;
            }

            bool operator<=(const iterator &other) const
            {
                return this->ptr <= other.ptr;
            }

            bool operator>=(const iterator &other) const
            {
                return this->ptr >= other.ptr;
            }

            operator const_iterator() const
            {
                return const_iterator(ptr);
            }
        };

        size_type size() const { return size_; }

        bool empty() const { return size_ == 0; }

        size_type capacity() const { return capacity_; }

        void reserve(size_type n)
        {
            if (n <= capacity_)
            {
                return;
            }
            reallocate(n);
        }

        void clear()
        {
            for (size_type i = 0; i < size_; i++)
            {
                arr_[i].~T();
            }
            size_ = 0;
        }

        vector() = default;
        vector(size_type sz) : size_(sz), capacity_(sz)
        {
            arr_ = static_cast<T *>(::operator new(sz * sizeof(T)));
            construction_guard guard(arr_, 0);
            for (size_type i = 0; i < sz; i++)
            {
                // 不分配内存，只在指定位置构造
                new (arr_ + i) T();
                guard.count++;
            }
            guard.release();
        }
        vector(size_type sz, const T &val) : size_(sz), capacity_(sz)
        {
            arr_ = static_cast<T *>(::operator new(sz * sizeof(T)));
            construction_guard guard(arr_, 0);
            for (size_type i = 0; i < sz; i++)
            {
                // 不分配内存，只在指定位置构造
                new (arr_ + i) T(val);
                guard.count++;
            }
            guard.release();
        }
        vector(const vector &other)
        {
            reserve(other.capacity_);
            construction_guard guard(arr_, 0);
            for (size_type i = 0; i < other.size_; i++)
            {
                new (arr_ + i) T(other.arr_[i]);
                guard.count++;
            }
            guard.release();
            size_ = other.size_;
        }
        vector(vector &&other) noexcept : arr_(other.arr_), size_(other.size_), capacity_(other.capacity_)
        {
            other.arr_ = nullptr;
            other.size_ = 0;
            other.capacity_ = 0;
        }

        vector(std::initializer_list<T> il) : vector(il.begin(), il.end()) {} // 委托给范围构造

        template <typename InputIt>
        vector(InputIt first, InputIt last)
        {
            size_ = 0;
            capacity_ = 0;
            arr_ = nullptr;

            for (InputIt it = first; it != last; ++it)
            {
                push_back(*it);
            }
        }

        reference operator[](size_type idx)
        {
            if (idx >= size_)
            {
                throw std::logic_error("下标越界！");
            }
            return arr_[idx];
        }
        const_reference operator[](size_type idx) const
        {
            if (idx >= size_)
            {
                throw std::logic_error("下标越界！");
            }
            return arr_[idx];
        }

        ~vector()
        {
            clear();                 // 逐个销毁元素
            ::operator delete(arr_); // 释放内存
        }

        void push_back(const T &val)
        {
            emplace_back(val);
        }
        void push_back(T &&val)
        {
            emplace_back(std::move(val));
        }

        template <typename... Args>
        T &emplace_back(Args &&...args)
        {
            if (size_ == capacity_)
            {
                reallocate(capacity_ == 0 ? 1 : capacity_ * 2);
            }
            new (arr_ + size_) T(std::forward<Args>(args)...);
            return arr_[size_++];
        }

        void pop_back()
        {
            if (size_ >= 1)
            {
                arr_[size_ - 1].~T();
                size_--;
            }
        }

        void swap(vector &other) noexcept
        {
            T *tmp_arr = arr_;
            size_type tmp_size = size_;
            size_type tmp_cap = capacity_;

            arr_ = other.arr_;
            size_ = other.size_;
            capacity_ = other.capacity_;

            other.arr_ = tmp_arr;
            other.size_ = tmp_size;
            other.capacity_ = tmp_cap;
        }

        vector &operator=(const vector &that)
        {
            if (this != &that)
            {
                // copy and swap
                vector tmp(that);
                this->swap(tmp);
            }
            return *this;
        }

        vector &operator=(vector &&that) noexcept
        {
            if (this != &that)
            {
                for (size_type i = 0; i < size_; i++)
                {
                    (arr_ + i)->~T();
                }
                ::operator delete(arr_);
                arr_ = that.arr_;
                size_ = that.size_;
                capacity_ = that.capacity_;

                that.arr_ = nullptr;
                that.size_ = 0;
                that.capacity_ = 0;
            }
            return *this;
        }

        iterator begin() { return iterator(arr_); }

        iterator end() { return iterator(size_ == 0 ? arr_ : (arr_ + size_)); }

        const_iterator begin() const { return const_iterator(arr_); }

        const_iterator end() const { return const_iterator(size_ == 0 ? arr_ : (arr_ + size_)); }

        const_iterator cbegin() const { return begin(); }

        const_iterator cend() const { return end(); }

        reference front()
        {
            return *arr_;
        }

        reference back()
        {
            return *(arr_ + size_ - 1);
        }

        const_reference front() const
        {
            return *arr_;
        }

        const_reference back() const
        {
            return *(arr_ + size_ - 1);
        }

        iterator erase(iterator pos)
        {
            for (auto it = pos + 1; it != end(); it++)
            {
                *(it - 1) = std::move_if_noexcept(*(it));
            }
            // 应当析构原来的最后一个元素
            (arr_ + size_ - 1)->~T();

            size_--;
            return pos;
        }

        iterator erase(iterator first, iterator last)
        {
            if (first == last)
            {
                return first;
            }
            size_type n = static_cast<size_type>(last - first);
            for (auto it = last; it != end(); it++)
            {
                *(it - n) = std::move_if_noexcept(*it);
            }
            // 析构后n个元素
            for (size_type i = 0; i < n; i++)
            {
                (arr_ + size_ - 1 - i)->~T();
            }
            size_ -= n;
            return first;
        }

        iterator insert(iterator pos, const T &val)
        {
            size_type idx = (pos == end() ? size_ : static_cast<size_type>(pos - begin())); // 扩容后pos会失效，因此需要先记录下标
            T tmp = val;
            // val可能是vector内部元素,防止插入过程中扩容等因素导致val失效,先拷贝一份
            if (size_ == capacity_)
            {
                reallocate(capacity_ == 0 ? 1 : size_ * 2);
            }
            pos = begin() + idx;

            // 末尾插入，等同于push_back
            if (pos == end())
            {
                push_back(tmp);
            }
            else
            {
                // 单独处理最后一个元素的右移,因为末尾是裸内存
                new (arr_ + size_) T(std::move(arr_[size_ - 1]));

                for (auto it = end() - 1; it != pos; it--)
                {
                    *it = std::move(*(it - 1));
                }
                *pos = tmp;
                size_++;
            }
            return pos;
        }

        template <typename lesstype = less<>, typename tar_type>
        iterator lower_bound(iterator first, iterator last, const tar_type &tar, lesstype cmp = lesstype{})
        {
            iterator l = first;
            iterator r = last - 1;
            iterator mid = l + (r - l) / 2;
            while (r - l >= 0 && l != last)
            {
                mid = l + (r - l) / 2;
                if (cmp(*mid, tar))
                {
                    l = mid + 1;
                }
                else
                {
                    if (mid != first && !cmp(*(mid - 1), tar))
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        return mid;
                    }
                }
            }
            return last;
        }

        template <typename lesstype = less<>, typename tar_type>
        const_iterator lower_bound(const_iterator first, const_iterator last, const tar_type &tar, lesstype cmp = lesstype{}) const
        {
            const_iterator l = first;
            const_iterator r = last - 1;
            const_iterator mid = l + (r - l) / 2;
            while (r - l >= 0 && l != last)
            {
                mid = l + (r - l) / 2;
                if (cmp(*mid, tar))
                {
                    l = mid + 1;
                }
                else
                {
                    if (mid != first && !cmp(*(mid - 1), tar))
                    {
                        r = mid - 1;
                    }
                    else
                    {
                        return mid;
                    }
                }
            }
            return last;
        }
    };

    template <typename T>
    void swap(vector<T> &a, vector<T> &b) noexcept
    {
        a.swap(b);
    }

}

#endif

#ifndef GYX_MY_STL_SORTS_HPP
#define GYX_MY_STL_SORTS_HPP

namespace gyx
{
    class sorter // 排序类
    {
    private:
        // 选择
        template <typename random_it_type, typename cmp_type>
        int select(random_it_type begin, random_it_type end, cmp_type cmp, int cnt_of_sorted)
        // 返回目前最大的数的下标，如果已排序好，返回-91
        {
            int n = end - begin;
            bool is_sorted = true;
            int idx_selected = 0;
            for (int i = 1; i < n - cnt_of_sorted; i++)
            {
                if (!cmp(*(begin + i), *(begin + idx_selected)))
                {
                    idx_selected = i;
                }
                else
                {
                    is_sorted = false;
                }
            }
            return is_sorted ? -91 : idx_selected;
        }

        template <typename random_it_type, typename cmp_type>
        void quick_sort_impl(random_it_type begin, random_it_type end, cmp_type cmp) // 快排的递归实现
        {
            int n = end - begin;
            if (n <= 1)
            {
                return;
            }

            auto pivot = *(begin + n / 2);
            int left = 0;
            int right = n - 1;
            while (left <= right)
            {
                while (cmp(*(begin + left), pivot))
                {
                    left++;
                }
                while (cmp(pivot, *(begin + right)))
                {
                    right--;
                }
                if (left <= right)
                {
                    swap(*(begin + left), *(begin + right));
                    left++;
                    right--;
                }
            }

            if (right >= 0)
            {
                quick_sort_impl(begin, begin + right + 1, cmp);
            }
            if (left < n)
            {
                quick_sort_impl(begin + left, end, cmp);
            }
        }

    public:
        // 名次排序(即计数排序)
        template <typename random_it_type, typename cmp_type = less<>>
        void rank_sort(random_it_type begin, random_it_type end, cmp_type cmp = cmp_type{})
        {
            int n = end - begin;
            using elem_type = typename RemoveRef<decltype(*begin)>::type;
            int *rank = new int[n];
            for (int i = 0; i < n; i++)
            {
                rank[i] = 0;
            }
            // 算rank
            for (auto it1 = begin; it1 != end; it1++)
            {
                for (auto it2 = begin; it2 != it1; it2++)
                {
                    if (cmp(*it1, *it2))
                    {
                        rank[it2 - begin]++;
                    }
                    else
                    {
                        rank[it1 - begin]++;
                    }
                }
            }
            // 根据rank排序
            elem_type *sorted = new elem_type[n];
            for (int i = 0; i < n; i++)
            {
                sorted[rank[i]] = *(begin + i);
            }

            // 覆盖原数组
            for (int i = 0; i < n; i++)
            {
                *(begin + i) = sorted[i];
            }

            // 释放内存
            delete[] rank;
            delete[] sorted;
        }

        // 及时终止的选择排序
        template <typename random_it_type, typename cmp_type = less<>>
        void select_sort(random_it_type begin, random_it_type end, cmp_type cmp = cmp_type{})
        {
            int n = end - begin;
            int cnt_of_sorted = 0;
            while (cnt_of_sorted < n)
            {
                int idx_of_selected = select(begin, end, cmp, cnt_of_sorted);
                if (idx_of_selected >= 0)
                {
                    swap(*(begin + idx_of_selected), *(begin + n - 1 - cnt_of_sorted));
                    cnt_of_sorted++;
                }
                else
                {
                    // 有序，及时退出
                    return;
                }
            }
        }

        // 快速排序
        template <typename random_it_type, typename cmp_type = less<>>
        void quick_sort(random_it_type begin, random_it_type end, cmp_type cmp = cmp_type{})
        {
            quick_sort_impl(begin, end, cmp);
        }

        // 及时终止的冒泡排序
        template <typename random_it_type, typename cmp_type = less<>>
        void bubble_sort(random_it_type begin, random_it_type end, cmp_type cmp = cmp_type{})
        {
            int n = end - begin;
            for (int i = 0; i < n; i++)
            {
                bool is_sorted = true;
                for (int j = 1; j < n - i; j++)
                {
                    if (cmp(*(begin + j), *(begin + j - 1)))
                    {
                        swap(*(begin + j), *(begin + j - 1));
                        is_sorted = false;
                    }
                }
                if (is_sorted)
                {
                    return;
                }
            }
        }

        // 插入排序
        template <typename random_it_type, typename cmp_type = less<>>
        void insert_sort(random_it_type begin, random_it_type end, cmp_type cmp = cmp_type{})
        {
            int n = end - begin;
            for (int i = 1; i < n; i++)
            {
                for (int j = i; j >= 1; j--)
                {
                    if (cmp(*(begin + j), *(begin + j - 1)))
                    {
                        swap(*(begin + j), *(begin + j - 1));
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    };

} // namespace gyx

#endif

#include <iostream>
#ifndef SPARSE_MATRIX_HPP
#define SPARSE_MATRIX_HPP

#include <utility>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace gyx;

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

        vector<int> other_row_start(other.row_cnt_ + 1); // other的行索引数组，第i行在data_中的[ other_row_start[i] , other_row_start[i+1] )

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
        sorter st;
        st.quick_sort(data_.begin(), data_.end(), csr_sorter_less());
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

#endif

using namespace gyx;

#define RESET 1
#define MULTI 2
#define ADD 3
#define OUTPUT 4
#define ROTATE 5

void one_operation(sparse_matrix<int> &matrix)
{
    int op;
    std::cin >> op;
    switch (op)
    {
    case RESET:
    {
        int n, m;
        std::cin >> n >> m;
        matrix.reset(n, m);
        break;
    }
    case MULTI:
    {
        int n, m;
        std::cin >> n >> m;
        sparse_matrix<int> y(n, m);
        int t;
        std::cin >> t;
        for (int i = 0; i < t; i++)
        {
            int r, c, v;
            std::cin >> r >> c >> v;
            y.push_back_to_the_none_zero_table(r - 1, c - 1, v);
        }
        try
        {
            matrix *= y;
        }
        catch (const sparse_matrix<int>::SizeUnmatch &e)
        {
            matrix = move(y);
            std::cout << -1 << "\n";
        }
        break;
    }
    case ADD:
    {
        int n, m;
        std::cin >> n >> m;
        sparse_matrix<int> y(n, m);
        int t;
        std::cin >> t;
        for (int i = 0; i < t; i++)
        {
            int r, c, v;
            std::cin >> r >> c >> v;
            y.push_back_to_the_none_zero_table(r - 1, c - 1, v);
        }
        try
        {
            matrix += y;
        }
        catch (const sparse_matrix<int>::SizeUnmatch &e)
        {
            matrix = move(y);
            std::cout << -1 << "\n";
        }
        break;
    }

    case OUTPUT:
    {
        std::cout << matrix;
        break;
    }
    case ROTATE:
    {
        matrix.rotate();
        break;
    }

    default:
        break;
    }
}

int main()
{
    int w;
    std::cin >> w;
    sparse_matrix<int> matrix;
    for (int i = 0; i < w; i++)
    {
        one_operation(matrix);
    }
}
