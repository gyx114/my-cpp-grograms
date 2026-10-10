#ifndef MY_STACK_HPP
#define MY_STACK_HPP

#include "my_vector.hpp"
#include "my_utils.hpp"

template <typename T, typename Container = my_vector<T>>
class my_stack
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

    my_stack() {}
    ~my_stack() {}
    my_stack(const my_stack &other) : data_(other.data_) {}
    my_stack(my_stack &&other) noexcept : data_(my_move(other.data_)) {}
    explicit my_stack(const Container &other_data) : data_(other_data) {}
    explicit my_stack(Container &&other_data) noexcept : data_(my_move(other_data)) {}

    my_stack &operator=(const my_stack &other)
    {
        data_ = other.data_;
        return *this;
    }
    my_stack &operator=(my_stack &&other) noexcept
    {
        data_ = my_move(other.data_);
        return *this;
    }

    my_stack &operator=(const Container &other_data)
    {
        data_ = other_data;
        return *this;
    }
    my_stack &operator=(Container &&other_data) noexcept
    {
        data_ = my_move(other_data);
        return *this;
    }

    bool empty() const noexcept { return data_.empty(); }
    size_type size() const noexcept { return data_.size(); }
    value_type &top() { return data_.back(); }
    const value_type &top() const { return data_.back(); }
    void push(const value_type &val) { data_.push_back(val); }
    void push(value_type &&val) { data_.push_back(my_move(val)); }
    void pop() { data_.pop_back(); }

    void swap(my_stack &other) noexcept
    {
        data_.swap(other.data_);
    }
};

template <typename T>
void swap(my_stack<T> &a, my_stack<T> &b) noexcept
{
    a.swap(b);
}

#endif
