#ifndef MY_VECTOR
#define MY_VECTOR

#include <stdexcept>
#include <utility> // std::move / std::forward / std::move_if_noexcept
#include <new>     // placement new / ::operator new

template <typename T>
class my_vector
{
private:
    T *arr_ = nullptr;
    int size_ = 0;
    int capacity_ = 0;

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

        const_iterator operator+(int n) const
        {
            return const_iterator(ptr + n);
        }

        const_iterator &operator+=(int n)
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

        const_iterator operator-(int n) const
        {
            return const_iterator(ptr - n);
        }

        int operator-(const const_iterator &rht) const
        {
            return ptr - rht.ptr;
        }

        const_iterator &operator-=(int n)
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

        T &operator*()
        {
            return *ptr;
        }

        const T &operator*() const
        {
            return *ptr;
        }

        T *operator->()
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

        iterator operator+(int n) const
        {
            return iterator(ptr + n);
        }

        iterator &operator+=(int n)
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

        iterator operator-(int n) const
        {
            return iterator(ptr - n);
        }

        int operator-(const iterator &rht) const
        {
            return ptr - rht.ptr;
        }

        iterator &operator-=(int n)
        {
            ptr -= n;
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

    int size() const
    {
        return size_;
    }

    int capacity() const
    {
        return capacity_;
    }

    void reserve(int n)
    {
        if (n <= capacity_)
        {
            return;
        }
        reallocate(n);
    }

    void reallocate(int n) // 扩容
    {
        T *new_arr = static_cast<T *>(::operator new(n * sizeof(T))); // 分配内存而不初始化
        // 类型必须是T*，方便指针偏移，对单个位置赋值

        // 移动或者拷贝
        for (int i = 0; i < size_; i++)
        {
            new (new_arr + i) T(std::move_if_noexcept(arr_[i]));
        }

        // 销毁旧元素
        for (int i = 0; i < size_; i++)
        {
            arr_[i].~T(); // 对每个对象析构，让内存变为裸内存
        }
        ::operator delete(arr_);
        arr_ = new_arr;
        capacity_ = n;
    }

    void clear()
    {
        for (int i = 0; i < size_; i++)
        {
            arr_[i].~T();
        }
        size_ = 0;
    }

    my_vector() = default;
    my_vector(int sz) : size_(sz), capacity_(sz)
    {
        if (sz < 0)
        {
            throw std::logic_error("size不能为负!");
        }
        arr_ = static_cast<T *>(::operator new(sz * sizeof(T)));
        for (int i = 0; i < sz; i++)
        {
            // 不分配内存，只在指定位置构造
            new (arr_ + i) T();
        }
    }
    my_vector(int sz, const T &val) : size_(sz), capacity_(sz)
    {
        if (sz < 0)
        {
            throw std::logic_error("size不能为负!");
        }
        arr_ = static_cast<T *>(::operator new(sz * sizeof(T)));
        for (int i = 0; i < sz; i++)
        {
            // 不分配内存，只在指定位置构造
            new (arr_ + i) T(val);
        }
    }
    my_vector(const my_vector &other)
    {
        reserve(other.capacity_);
        for (int i = 0; i < other.size_; i++)
        {
            new (arr_ + i) T(other.arr_[i]);
        }
        size_ = other.size_;
    }
    my_vector(my_vector &&other) noexcept : arr_(other.arr_), size_(other.size_), capacity_(other.capacity_)
    {
        other.arr_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
    }

    T &operator[](int idx)
    {
        if (idx < 0 || idx >= size_)
        {
            throw std::logic_error("下标越界！");
        }
        return arr_[idx];
    }
    const T &operator[](int idx) const
    {
        if (idx < 0 || idx >= size_)
        {
            throw std::logic_error("下标越界！");
        }
        return arr_[idx];
    }

    ~my_vector()
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

    void swap(my_vector &other)
    {
        T *tmp_arr = arr_;
        int tmp_size = size_;
        int tmp_cap = capacity_;

        arr_ = other.arr_;
        size_ = other.size_;
        capacity_ = other.capacity_;

        other.arr_ = tmp_arr;
        other.size_ = tmp_size;
        other.capacity_ = tmp_cap;
    }

    my_vector &operator=(const my_vector &that)
    {
        if (this != &that)
        {
            // copy and swap
            my_vector tmp(that);
            this->swap(tmp);
        }
        return *this;
    }

    my_vector &operator=(my_vector &&that) noexcept
    {
        if (this != &that)
        {
            for (int i = 0; i < size_; i++)
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

    iterator begin()
    {
        return iterator(arr_);
    }

    iterator end()
    {
        return iterator(size_ == 0 ? arr_ : (arr_ + size_));
    }

    const_iterator begin() const
    {
        return const_iterator(arr_);
    }

    const_iterator end() const
    {
        return const_iterator(size_ == 0 ? arr_ : (arr_ + size_));
    }

    T &front()
    {
        return *arr_;
    }

    T &back()
    {
        return *(arr_ + size_ - 1);
    }

    const T &front() const
    {
        return *arr_;
    }

    const T &back() const
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
        int n = last - first;
        for (auto it = last; it != end(); it++)
        {
            *(it - n) = std::move_if_noexcept(*it);
        }
        // 析构后n个元素
        for (int i = 0; i < n; i++)
        {
            (arr_ + size_ - 1 - i)->~T();
        }
        size_ -= n;
        return first;
    }

    iterator insert(iterator pos, const T &val)
    {
        int idx = (pos == end() ? size_ : pos - begin()); // 扩容后pos会失效，因此需要先记录下标
        if (size_ == capacity_)
        {
            reallocate(capacity_ == 0 ? 1 : size_ * 2);
        }
        pos = begin() + idx;

        // 末尾插入，等同于push_back
        if (pos == end())
        {
            push_back(val);
        }
        else
        {
            // 单独处理最后一个元素的右移
            new (arr_ + size_) T(std::move(arr_[size_ - 1]));

            for (auto it = end() - 1; it != pos; it--)
            {
                *it = std::move(*(it - 1));
            }
            *pos = val;
            size_++;
        }
        return pos;
    }
};

#endif
