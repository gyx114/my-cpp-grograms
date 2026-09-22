#ifndef MY_LIST
#define MY_LIST

#include "my_utils.hpp"
#include <utility> //std::move
#include <cstddef> //size_t
#include <iostream>

struct base_node // 供哨兵节点使用，无数据，只有prev和next
{
    base_node *next_;
    base_node *prev_;

    base_node(base_node *next = nullptr, base_node *prev = nullptr) : next_(next), prev_(prev) {}
    virtual ~base_node() {}
};

template <typename T>
struct node : public base_node
{
    T data_;

    node(const T &data, base_node *next = nullptr, base_node *prev = nullptr) : base_node(next, prev), data_(data) {}
    node(T &&data, base_node *next = nullptr, base_node *prev = nullptr) : base_node(next, prev), data_(std::move(data)) {}

    ~node() {}
};

template <typename T>
class my_list // 双向循环链表
{
private:
    base_node dummy; // 哨兵节点，栈上初始化，自己析构
    size_t size_;

public:
    class iterator // 双向迭代器
    {
    private:
        base_node *pnode_;
        friend class my_list;

    public:
        explicit iterator(base_node *pnode) : pnode_(pnode) {}
        iterator(const iterator &other) : pnode_(other.pnode_) {}
        ~iterator() = default;

        iterator &operator=(const iterator &other)
        {
            pnode_ = other.pnode_;
            return *this;
        }

        T &operator*() const
        {
            return static_cast<node<T> *>(pnode_)->data_;
        }

        T *operator->() const
        {
            return &(operator*());
        }

        iterator &operator++()
        {
            pnode_ = pnode_->next_;
            return *this;
        }

        iterator operator++(int)
        {
            auto tmp = iterator(*this);
            pnode_ = pnode_->next_;
            return tmp;
        }
        iterator &operator--()
        {
            pnode_ = pnode_->prev_;
            return *this;
        }

        iterator operator--(int)
        {
            auto tmp = iterator(*this);
            pnode_ = pnode_->prev_;
            return tmp;
        }

        bool operator==(const iterator &other) const
        {
            return pnode_ == other.pnode_;
        }
        bool operator!=(const iterator &other) const
        {
            return pnode_ != other.pnode_;
        }
    };

    class const_iterator // 双向const迭代器
    {
    private:
        const base_node *pnode_;
        friend class my_list;

    public:
        explicit const_iterator(const base_node *pnode) : pnode_(pnode) {}
        const_iterator(const const_iterator &other) : pnode_(other.pnode_) {}
        ~const_iterator() = default;

        const_iterator &operator=(const const_iterator &other)
        {
            pnode_ = other.pnode_;
            return *this;
        }

        const T &operator*() const
        {
            return static_cast<const node<T> *>(pnode_)->data_;
        }

        const T *operator->() const
        {
            return &(operator*());
        }

        const_iterator &operator++()
        {
            pnode_ = pnode_->next_;
            return *this;
        }

        const_iterator operator++(int)
        {
            auto tmp = const_iterator(*this);
            pnode_ = pnode_->next_;
            return tmp;
        }
        const_iterator &operator--()
        {
            pnode_ = pnode_->prev_;
            return *this;
        }

        const_iterator operator--(int)
        {
            auto tmp = const_iterator(*this);
            pnode_ = pnode_->prev_;
            return tmp;
        }

        bool operator==(const const_iterator &other) const
        {
            return pnode_ == other.pnode_;
        }
        bool operator!=(const const_iterator &other) const
        {
            return pnode_ != other.pnode_;
        }
    };

    /*---构造/析构---*/
    my_list() : dummy(&dummy, &dummy), size_(0) {}
    ~my_list() { clear(); }
    my_list(const my_list &other) = delete;
    my_list &operator=(const my_list &other) = delete;

    /*---容量---*/
    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }

    /*---迭代器---*/
    iterator begin() { return iterator(dummy.next_); }
    iterator end() { return iterator(&dummy); }
    const_iterator begin() const { return const_iterator(dummy.next_); }
    const_iterator end() const { return const_iterator(&dummy); }
    const_iterator cbegin() const { return begin(); }
    const_iterator cend() const { return end(); }

    /*---插入/删除---*/
    iterator insert(iterator pos, const T &val)
    {
        base_node *p = pos.pnode_;
        node<T> *new_node = new node<T>(val, p, p->prev_);
        p->prev_->next_ = new_node;
        p->prev_ = new_node;
        size_++;
        return iterator(new_node);
    }

    iterator insert(iterator pos, T &&val)
    {
        base_node *p = pos.pnode_;
        node<T> *new_node = new node<T>(std::move(val), p, p->prev_);
        p->prev_->next_ = new_node;
        p->prev_ = new_node;
        size_++;
        return iterator(new_node);
    }

    iterator erase(iterator pos)
    {
        if (pos == end())
        {
            return end();
        }
        base_node *p = pos.pnode_;
        base_node *pnext_ = p->next_;
        p->prev_->next_ = p->next_;
        p->next_->prev_ = p->prev_;
        delete p; // 虚析构自己处理去吧
        size_--;
        return iterator(pnext_);
    }

    iterator erase(const T &val)
    {
        iterator it = search(val);
        if (it == end())
        {
            return it;
        }
        iterator it_next = it;
        it_next++;
        erase(it);
        return it_next;
    }

    /*---清空---*/
    void clear()
    {
        base_node *cur = dummy.next_;
        while (cur != &dummy)
        {
            base_node *nxt = cur->next_;
            delete cur;
            cur = nxt;
        }
        dummy.next_ = &dummy;
        dummy.prev_ = &dummy;
        size_ = 0;
    }

    /*---头尾操作---*/
    void push_back(const T &val) { insert(end(), val); }
    void push_back(T &&val) { insert(end(), std::move(val)); }
    void push_front(const T &val) { insert(begin(), val); }
    void push_front(T &&val) { insert(begin(), std::move(val)); }

    void pop_back()
    {
        if (size_)
        {
            erase(iterator(dummy.prev_));
        }
    }
    void pop_front()
    {
        if (size_)
        {
            erase(iterator(dummy.next_));
        }
    }

    T &front() { return *begin(); }
    T &back() { return *(iterator(dummy.prev_)); }
    const T &front() const { return *begin(); }
    const T &back() const { return *(const_iterator(dummy.prev_)); }

    /*---顺序搜索---*/
    iterator search(const T &val)
    {
        iterator it = begin();
        while (it != end() && *it != val)
        {
            it++;
        }
        return it;
    }
    const_iterator search(const T &val) const
    {
        const_iterator it = begin();
        while (it != end() && *it != val)
        {
            it++;
        }
        return it;
    }

    /*---原地逆置---*/
    void reverse()
    {
        base_node *p = &dummy;
        do
        {
            my_swap(p->prev_, p->next_);
            p = p->prev_;
        } while (p != &dummy);
    }

    /*---输出链表---*/
    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const my_list<U> &lst);
};

template <typename T>
inline std::ostream &operator<<(std::ostream &os, const my_list<T> &lst)
{
    auto it = lst.begin();
    while (it != lst.end())
    {
        os << *it << ' ';
        it++;
    }
    os << std::endl;
    return os;
}

#endif
