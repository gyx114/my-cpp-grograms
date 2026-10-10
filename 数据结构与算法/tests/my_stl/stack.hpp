#ifndef GYX_MY_STL_STACK_HPP
#define GYX_MY_STL_STACK_HPP

#include "vector.hpp"
#include "utility.hpp"

namespace gyx
{
    template <typename T, typename Container = vector<T>>
    class stack
    {
    private:
        Container data_;

    public:
        using container_type = Container;
        using value_type = typename Container::value_type;
        using size_type = typename Container::size_type;
        using difference_type = typename Container::difference_type;
        using reference = typename Container::reference;
        using const_reference = typename Container::const_reference;
        using pointer = typename Container::pointer;
        using const_pointer = typename Container::const_pointer;

        stack() {}
        ~stack() {}
        stack(const stack &other) : data_(other.data_) {}
        stack(stack &&other) noexcept : data_(move(other.data_)) {}
        explicit stack(const Container &other_data) : data_(other_data) {}
        explicit stack(Container &&other_data) noexcept : data_(move(other_data)) {}

        stack &operator=(const stack &other)
        {
            data_ = other.data_;
            return *this;
        }
        stack &operator=(stack &&other) noexcept
        {
            data_ = move(other.data_);
            return *this;
        }

        stack &operator=(const Container &other_data)
        {
            data_ = other_data;
            return *this;
        }
        stack &operator=(Container &&other_data) noexcept
        {
            data_ = move(other_data);
            return *this;
        }

        bool empty() const noexcept { return data_.empty(); }
        size_type size() const noexcept { return data_.size(); }
        value_type &top() { return data_.back(); }
        const value_type &top() const { return data_.back(); }
        void push(const value_type &val) { data_.push_back(val); }
        void push(value_type &&val) { data_.push_back(move(val)); }
        void pop() { data_.pop_back(); }

        void swap(stack &other) noexcept
        {
            data_.swap(other.data_);
        }
    };

    template <typename T>
    void swap(stack<T> &a, stack<T> &b) noexcept
    {
        a.swap(b);
    }

} // namespace gyx

#endif
