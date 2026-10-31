#ifndef GYX_MY_STL_TREE_TRAVERSE_HPP
#define GYX_MY_STL_TREE_TRAVERSE_HPP

#include "stack.hpp"
#include "queue.hpp"

namespace gyx
{
    struct recursive_t // 递归标签
    {
    };
    struct iterative_t // 迭代标签
    {
    };

#pragma region 非const遍历实现
    template <typename tree_node, typename Op>
    void pre_order_impl_recursion(tree_node *rt, Op &op) // 递归版先序遍历实现
    {
        if (!rt)
        {
            return;
        }
        op(rt);
        pre_order_impl_recursion(rt->left(), op);
        pre_order_impl_recursion(rt->right(), op);
    }
    template <typename tree_node, typename Op>
    void in_order_impl_recursion(tree_node *rt, Op &op) // 递归版中序遍历实现
    {
        if (!rt)
        {
            return;
        }
        in_order_impl_recursion(rt->left(), op);
        op(rt);
        in_order_impl_recursion(rt->right(), op);
    }
    template <typename tree_node, typename Op>
    void post_order_impl_recursion(tree_node *rt, Op &op) // 递归版后序遍历实现
    {
        if (!rt)
        {
            return;
        }
        post_order_impl_recursion(rt->left(), op);
        post_order_impl_recursion(rt->right(), op);
        op(rt);
    }

    template <typename tree_node, typename Op>
    void level_order_impl(tree_node *rt, Op &op) // 层序遍历，使用队列
    {
        if (!rt)
        {
            return;
        }
        queue<tree_node *> q;
        q.push(rt);
        while (q.size())
        {
            auto tmp = q.front();
            op(tmp);
            if (tmp->left())
            {
                q.push(tmp->left());
            }
            if (tmp->right())
            {
                q.push(tmp->right());
            }
            q.pop();
        }
    }

    template <typename tree_node, typename Op>
    void pre_order_impl_iter(tree_node *rt, Op &op) // 迭代版本先序遍历实现
    {
        stack<tree_node *> st;
        tree_node *cur = rt;
        while (cur || !st.empty())
        {
            while (cur)
            {
                if (cur->right())
                {
                    st.push(cur->right());
                }
                op(cur);
                cur = cur->left();
            }
            if (!st.empty())
            {
                cur = st.top();
                st.pop();
            }
        }
    }
    template <typename tree_node, typename Op>
    void in_order_impl_iter(tree_node *rt, Op &op) // 迭代版本中序遍历实现
    {
        stack<tree_node *> st;
        tree_node *cur = rt;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left();
            }
            if (!st.empty())
            {
                cur = st.top()->right();
                op(st.top());
                st.pop();
            }
        }
    }
    template <typename tree_node, typename Op>
    void post_order_impl_iter(tree_node *rt, Op &op) // 迭代版后序遍历实现
    {
        stack<tree_node *> st;
        tree_node *cur = rt;
        tree_node *last = nullptr;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left();
            }
            if (!st.empty())
            {
                cur = st.top();
                if (cur->right() && cur->right() != last)
                {
                    cur = cur->right();
                }
                else
                {
                    last = cur;
                    op(cur);
                    st.pop();
                    cur = nullptr;
                }
            }
        }
    }
#pragma endregion

#pragma region const遍历实现
    template <typename tree_node, typename Op>
    void pre_order_impl_recursion(const tree_node *rt, Op &op) // 递归版先序遍历实现
    {
        if (!rt)
        {
            return;
        }
        op(rt);
        pre_order_impl_recursion(rt->left(), op);
        pre_order_impl_recursion(rt->right(), op);
    }
    template <typename tree_node, typename Op>
    void in_order_impl_recursion(const tree_node *rt, Op &op) // 递归版中序遍历实现
    {
        if (!rt)
        {
            return;
        }
        in_order_impl_recursion(rt->left(), op);
        op(rt);
        in_order_impl_recursion(rt->right(), op);
    }
    template <typename tree_node, typename Op>
    void post_order_impl_recursion(const tree_node *rt, Op &op) // 递归版后序遍历实现
    {
        if (!rt)
        {
            return;
        }
        post_order_impl_recursion(rt->left(), op);
        post_order_impl_recursion(rt->right(), op);
        op(rt);
    }

    template <typename tree_node, typename Op>
    void level_order_impl(const tree_node *rt, Op &op) // 层序遍历，使用队列
    {
        if (!rt)
        {
            return;
        }
        queue<const tree_node *> q;
        q.push(rt);
        while (q.size())
        {
            auto tmp = q.front();
            op(tmp);
            if (tmp->left())
            {
                q.push(tmp->left());
            }
            if (tmp->right())
            {
                q.push(tmp->right());
            }
            q.pop();
        }
    }

    template <typename tree_node, typename Op>
    void pre_order_impl_iter(const tree_node *rt, Op &op) // 迭代版本先序遍历实现
    {
        stack<const tree_node *> st;
        const tree_node *cur = rt;
        while (cur || !st.empty())
        {
            while (cur)
            {
                if (cur->right())
                {
                    st.push(cur->right());
                }
                op(cur);
                cur = cur->left();
            }
            if (!st.empty())
            {
                cur = st.top();
                st.pop();
            }
        }
    }
    template <typename tree_node, typename Op>
    void in_order_impl_iter(const tree_node *rt, Op &op) // 迭代版本中序遍历实现
    {
        stack<const tree_node *> st;
        const tree_node *cur = rt;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left();
            }
            if (!st.empty())
            {
                cur = st.top()->right();
                op(st.top());
                st.pop();
            }
        }
    }
    template <typename tree_node, typename Op>
    void post_order_impl_iter(const tree_node *rt, Op &op) // 迭代版后序遍历实现
    {
        stack<const tree_node *> st;
        const tree_node *cur = rt;
        const tree_node *last = nullptr;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left();
            }
            if (!st.empty())
            {
                cur = st.top();
                if (cur->right() && cur->right() != last)
                {
                    cur = cur->right();
                }
                else
                {
                    last = cur;
                    op(cur);
                    st.pop();
                    cur = nullptr;
                }
            }
        }
    }
#pragma endregion

} // namespace gyx

#endif
