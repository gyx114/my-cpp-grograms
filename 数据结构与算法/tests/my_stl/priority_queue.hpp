#ifndef GYX_MY_STL_PRIORITY_QUEUE_HPP
#define GYX_MY_STL_PRIORITY_QUEUE_HPP

#include "vector.hpp"
#include "utility.hpp"
#include <utility>
#include <initializer_list>

namespace gyx
{
    template <typename T, typename Container = vector<T>, typename Cmp = less<>>
    class priority_queue
    {
    private:
        Container data_; // 从下标0开始存数据

        constexpr int to_father(int idx) { return (idx + 1) / 2 - 1; }
        constexpr int to_left_son(int idx) { return (idx + 1) * 2 - 1; }
        constexpr int to_right_son(int idx) { return (idx + 1) * 2; }

        void down(int idx) // 以idx为根的树，向下维护大根性
        {
            auto cmp = Cmp{};
            auto l = to_left_son(idx);
            auto r = to_right_son(idx);
            bool dir_to_rht = l < data_.size() && r < data_.size() && cmp(data_[l], data_[r]);
            int son_idx = dir_to_rht ? r : l;
            while (son_idx < data_.size() && cmp(data_[idx], data_[son_idx]))
            {
                swap(data_[idx], data_[son_idx]);
                idx = son_idx;
                l = to_left_son(idx);
                r = to_right_son(idx);
                dir_to_rht = l < data_.size() && r < data_.size() && cmp(data_[l], data_[r]);
                son_idx = dir_to_rht ? to_right_son(idx) : to_left_son(idx);
            }
        }

    public:
        priority_queue() {}

        ~priority_queue() {}

        priority_queue(const vector<T> &init) : data_(init)
        {
            if (data_.size())
            {
                for (int i = to_father(data_.size() - 1); i >= 0; i--)
                {
                    down(i);
                }
            }
        }

        priority_queue(vector<T> &&init) : data_(move(init))
        {
            if (data_.size())
            {
                for (int i = to_father(data_.size() - 1); i >= 0; i--)
                {
                    down(i);
                }
            }
        }

        priority_queue(std::initializer_list<T> il) : data_(il)
        {
            if (data_.size())
            {
                for (int i = to_father(data_.size() - 1); i >= 0; i--)
                {
                    down(i);
                }
            }
        }

        template <typename InputIt, typename std::enable_if<detail::is_input_iterator<InputIt>::value, int>::type = 0>
        priority_queue(InputIt first, InputIt last) : data_(first, last)
        {
            if (data_.size())
            {
                for (int i = to_father(data_.size() - 1); i >= 0; i--)
                {
                    down(i);
                }
            }
        }

        priority_queue(const priority_queue &other) : data_(other.data_) {}
        priority_queue(priority_queue &&other) noexcept : data_(move(other.data_)) {}
        operator=(const priority_queue & other)
        {
            if (this != &other)
            {
                data_ = other.data_;
            }
            return *this;
        }
        operator=(priority_queue && other) noexcept
        {
            if (this != &other)
            {
                data_ = move(other.data_);
            }
            return *this;
        }

        void push(const T &val)
        {
            data_.push_back(val);
            int idx = data_.size() - 1;
            int dad_idx = to_father(idx);
            auto cmp = Cmp{};
            while (dad_idx != -1 && cmp(data_[dad_idx], data_[idx]))
            {
                swap(data_[dad_idx], data_[idx]);
                idx = dad_idx;
                dad_idx = to_father(idx);
            }
        }

        void push(T &&val)
        {
            data_.push_back(move(val));
            int idx = data_.size() - 1;
            int dad_idx = to_father(idx);
            auto cmp = Cmp{};
            while (dad_idx != -1 && cmp(data_[dad_idx], data_[idx]))
            {
                swap(data_[dad_idx], data_[idx]);
                idx = dad_idx;
                dad_idx = to_father(idx);
            }
        }

        template <typename... Args>
        void emplace(Args &&...args)
        {
            data_.emplace_back(std::forward<Args>(args)...);
            int idx = data_.size() - 1;
            int dad_idx = to_father(idx);
            auto cmp = Cmp{};
            while (dad_idx != -1 && cmp(data_[dad_idx], data_[idx]))
            {
                swap(data_[dad_idx], data_[idx]);
                idx = dad_idx;
                dad_idx = to_father(idx);
            }
        }

        void pop()
        {
            if (data_.size() > 1)
            {
                swap(data_[0], data_.back()); // 把最后一个和根互换
            }
            if (data_.size())
            {
                data_.pop_back();
            }
            down(0); // 维护大根性
        }

        typename Container::size_type size() const noexcept { return data_.size(); }

        const T &top() const { return data_.front(); }
    };

} // namespace gyx

#endif
