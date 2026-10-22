#ifndef GYX_MY_STL_QUEUE_HPP
#define GYX_MY_STL_QUEUE_HPP

#include "list.hpp"
#include "vector.hpp"
#include <utility>

namespace gyx
{
    template <typename T, typename Container = list<T>>
    class queue // 容器适配器
    {
    private:
        Container data_;

    public:
        using container_type = Container;
        using value_type = typename Container::value_type;
        using size_type = typename Container::size_type;
        using reference = typename Container::reference;
        using const_reference = typename Container::const_reference;
        using pointer = typename Container::pointer;
        using const_pointer = typename Container::const_pointer;

        queue() {}
        ~queue() {}
        queue(const queue &other) : data_(other.data_) {}
        queue(queue &&other) noexcept : data_(move(other.data_)) {}
        explicit queue(const Container &other_data) : data_(other_data) {}
        explicit queue(Container &&other_data) noexcept : data_(move(other_data)) {}

        queue &operator=(const queue &other)
        {
            data_ = other.data_;
            return *this;
        }
        queue &operator=(queue &&other) noexcept
        {
            data_ = move(other.data_);
            return *this;
        }

        queue &operator=(const Container &other_data)
        {
            data_ = other_data;
            return *this;
        }
        queue &operator=(Container &&other_data) noexcept
        {
            data_ = move(other_data);
            return *this;
        }

        bool empty() const noexcept { return data_.empty(); }
        size_type size() const noexcept { return data_.size(); }
        reference front() { return data_.front(); }
        const_reference front() const { return data_.front(); }
        reference back() { return data_.back(); }
        const_reference back() const { return data_.back(); }
        void push(const_reference val) { data_.push_back(val); }
        void push(value_type &&val) { data_.push_back(move(val)); }

        template <typename... Args>
        void emplace(Args &&...args)
        {
            data_.emplace_back(std::forward<Args>(args)...);
        }

        void pop() { data_.pop_front(); }

        void swap(queue &other) noexcept
        {
            data_.swap(other.data_);
        }
    };

    template <typename T>
    class queue<T, vector<T>> // vector特化
    {
    public:
        using Container = vector<T>;
        using value_type = typename Container::value_type;
        using size_type = typename Container::size_type;
        using reference = typename Container::reference;
        using const_reference = typename Container::const_reference;
        using pointer = typename Container::pointer;
        using const_pointer = typename Container::const_pointer;

    private:
        vector<T> data_;
        size_type begin_;
        size_type end_;
        size_type size_;

    public:
        queue() : data_(), begin_(0), end_(0), size_(0) {}
        ~queue() {}

        queue(const queue &other) = default;
        queue(queue &&other) noexcept : data_(move(other.data_)), begin_(other.begin_), end_(other.end_), size_(other.size_)
        {
            other.begin_ = 0;
            other.end_ = 0;
            other.size_ = 0;
        }
        explicit queue(const Container &other_data) : data_(other_data), begin_(0), end_(other_data.size() ? other_data.size() % other_data.capacity() : 0), size_(other_data.size()) {}

        explicit queue(Container &&other_data) noexcept : data_(move(other_data)), begin_(0)
        {
            size_ = data_.size();
            if (size_)
            {
                end_ = data_.size() % data_.capacity();
            }
            else
            {
                end_ = 0;
            }
        }

        queue &operator=(const queue &other) = default;
        queue &operator=(queue &&other)
        {
            if (this != &other)
            {
                data_ = move(other.data_);
                begin_ = other.begin_;
                end_ = other.end_;
                size_ = other.size_;

                other.begin_ = 0;
                other.end_ = 0;
                other.size_ = 0;
            }
            return *this;
        }

        queue &operator=(const Container &other_data)
        {
            data_ = other_data;
            begin_ = 0;
            size_ = other_data.size();
            end_ = size_ ? size_ % data_.capacity() : 0;
            return *this;
        }

        queue &operator=(Container &&other_data) noexcept
        {
            data_ = move(other_data);
            begin_ = 0;
            size_ = data_.size();
            end_ = size_ ? size_ % data_.capacity() : 0;
            return *this;
        }

        bool empty() const noexcept { return !size_; }
        size_type size() const noexcept { return size_; }

        reference front() { return data_[begin_]; }
        const_reference front() const { return data_[begin_]; }

        reference back() { return data_[(begin_ + size_ - 1) % data_.capacity()]; }
        const_reference back() const { return data_[(begin_ + size_ - 1) % data_.capacity()]; }

        void pop()
        {
            if (size_)
            {
                begin_ = (begin_ + 1) % data_.capacity();
                size_--;
            }
        }

        void push(const_reference val)
        {
            if (size_ < data_.capacity()) // 不扩容
            {
                if (end_ == data_.size())
                {
                    data_.push_back(val);
                }
                else
                {
                    data_[end_] = val;
                }
                end_ = (end_ + 1) % data_.capacity();
                size_++;
            }
            else // 扩容
            {
                vector<T> tmp;
                tmp.reserve(data_.capacity() * 2);
                for (size_type cnt = 0; cnt < data_.capacity(); cnt++)
                {
                    tmp.push_back(move(data_[(begin_ + cnt) % data_.capacity()]));
                }
                data_.swap(tmp);
                data_.push_back(val);
                begin_ = 0;
                end_ = data_.size();
                size_ = data_.size();
            }
        }

        void push(value_type &&val)
        {
            if (size_ < data_.capacity()) // 不扩容
            {
                if (end_ == data_.size())
                {
                    data_.push_back(move(val));
                }
                else
                {
                    data_[end_] = move(val);
                }
                end_ = (end_ + 1) % data_.capacity();
                size_++;
            }
            else // 扩容
            {
                vector<T> tmp;
                tmp.reserve(data_.capacity() * 2);
                for (size_type cnt = 0; cnt < data_.capacity(); cnt++)
                {
                    tmp.push_back(move(data_[(begin_ + cnt) % data_.capacity()]));
                }
                data_.swap(tmp);
                data_.push_back(move(val));
                begin_ = 0;
                end_ = data_.size();
                size_ = data_.size();
            }
        }

        template <typename... Args>
        void emplace(Args &&...args)
        {
            if (size_ < data_.capacity()) // 不扩容
            {
                if (end_ == data_.size())
                {
                    data_.emplace_back(std::forward<Args>(args)...);
                }
                else
                {
                    data_[end_] = value_type(std::forward<Args>(args)...);
                }
                end_ = (end_ + 1) % data_.capacity();
                size_++;
            }
            else // 扩容
            {
                vector<T> tmp;
                tmp.reserve(data_.capacity() * 2);
                for (size_type cnt = 0; cnt < data_.capacity(); cnt++)
                {
                    tmp.push_back(move(data_[(begin_ + cnt) % data_.capacity()]));
                }
                data_.swap(tmp);
                data_.emplace_back(std::forward<Args>(args)...);
                begin_ = 0;
                end_ = data_.size();
                size_ = data_.size();
            }
        }

        void swap(queue &other) noexcept
        {
            data_.swap(other.data_);
            gyx::swap(begin_, other.begin_);
            gyx::swap(end_, other.end_);
            gyx::swap(size_, other.size_);
        }
    };

    template <typename T, typename Container = list<T>>
    void swap(queue<T, Container> &a, queue<T, Container> &b) noexcept
    {
        a.swap(b);
    }

};

#endif
