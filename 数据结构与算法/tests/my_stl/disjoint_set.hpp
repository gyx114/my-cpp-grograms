#ifndef GYX_MY_STL_DISJOINT_SET_HPP
#define GYX_MY_STL_DISJOINT_SET_HPP

#include <stdexcept>

namespace gyx
{
    class disjoint_set // 并查集，需要把元素映射为1,2,3...
    {
    public:
        struct InvalidElem : public std::invalid_argument
        {
            InvalidElem() : std::invalid_argument("根本不存在这种编号") {}
        };

    private:
        size_t *father_;
        size_t size_;

        size_t find_father(size_t a)
        {
            size_t tmp = a;
            while (father_[tmp] != tmp)
            {
                father_[tmp] = father_[father_[tmp]];
                tmp = father_[tmp];
            }
            return tmp;
        }

    public:
        disjoint_set(size_t sz) : size_(sz), father_(static_cast<size_t *>(new size_t[sz + 1]))
        {
            for (size_t i = 0; i <= size_; i++)
            {
                father_[i] = i;
            }
        }
        ~disjoint_set() { delete[] father_; }

        disjoint_set(const disjoint_set &) = delete;
        disjoint_set &operator=(const disjoint_set &) = delete;

        void unite(size_t a, size_t b)
        {
            if (a == 0 || a > size_ || b == 0 || b > size_)
            {
                throw InvalidElem{};
            }
            father_[find_father(a)] = find_father(b);
        }

        bool check(size_t a, size_t b)
        {
            if (a == 0 || a > size_ || b == 0 || b > size_)
            {
                throw InvalidElem{};
            }
            return find_father(a) == find_father(b);
        }
    };

} // namespace gyx

#endif
