#ifndef GYX_BINARY_TREE_HPP
#define GYX_BINARY_TREE_HPP
#include "utility.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "vector.hpp"
#include <cstddef>
#include <type_traits>
#include <iostream>

namespace gyx
{
    template <typename T>
    class binary_tree
    {
    public:
        class tree_node
        {
            friend class binary_tree;

        private:
            T val_;
            tree_node *left_;
            tree_node *right_;

        public:
            explicit tree_node(const T &v, tree_node *l = nullptr, tree_node *r = nullptr) : val_(v), left_(l), right_(r) {}
            ~tree_node() {}

            tree_node(const tree_node &other) = default;
            tree_node(tree_node &&other) noexcept : val_(move(other.val_)), left_(other.left_), right_(other.right_)
            {
                other.left_ = nullptr;
                other.right_ = nullptr;
            }

            tree_node &operator=(const tree_node &other) = default;
            tree_node &operator=(tree_node &&other)
            {
                if (this != &other)
                {
                    val_ = move(other.val_);
                    left_ = other.left_;
                    right_ = other.right_;
                    other.left_ = nullptr;
                    other.right_ = nullptr;
                }
                return *this;
            }

            T &value() { return val_; }
            const T &value() const { return val_; }
            tree_node *left() { return left_; }
            tree_node *right() { return right_; }
            const tree_node *left() const { return left_; }
            const tree_node *right() const { return right_; }
        };

    private:
        tree_node *root_;

#pragma region 非const遍历实现
        template <typename Op>
        void pre_order_impl_recursion(tree_node *rt, Op &op) // 递归版先序遍历实现
        {
            if (!rt)
            {
                return;
            }
            op(rt);
            pre_order_impl_recursion(rt->left_, op);
            pre_order_impl_recursion(rt->right_, op);
        }
        template <typename Op>
        void in_order_impl_recursion(tree_node *rt, Op &op) // 递归版中序遍历实现
        {
            if (!rt)
            {
                return;
            }
            in_order_impl_recursion(rt->left_, op);
            op(rt);
            in_order_impl_recursion(rt->right_, op);
        }
        template <typename Op>
        void post_order_impl_recursion(tree_node *rt, Op &op) // 递归版后序遍历实现
        {
            if (!rt)
            {
                return;
            }
            post_order_impl_recursion(rt->left_, op);
            post_order_impl_recursion(rt->right_, op);
            op(rt);
        }

        template <typename Op>
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
                if (tmp->left_)
                {
                    q.push(tmp->left_);
                }
                if (tmp->right_)
                {
                    q.push(tmp->right_);
                }
                q.pop();
            }
        }

        template <typename Op>
        void pre_order_impl_iter(tree_node *rt, Op &op) // 迭代版本先序遍历实现
        {
            stack<tree_node *> st;
            tree_node *cur = rt;
            while (cur || !st.empty())
            {
                while (cur)
                {
                    if (cur->right_)
                    {
                        st.push(cur->right_);
                    }
                    op(cur);
                    cur = cur->left_;
                }
                if (!st.empty())
                {
                    cur = st.top();
                    st.pop();
                }
            }
        }
        template <typename Op>
        void in_order_impl_iter(tree_node *rt, Op &op) // 迭代版本中序遍历实现
        {
            stack<tree_node *> st;
            tree_node *cur = rt;
            while (cur || !st.empty())
            {
                while (cur)
                {
                    st.push(cur);
                    cur = cur->left_;
                }
                if (!st.empty())
                {
                    cur = st.top()->right_;
                    op(st.top());
                    st.pop();
                }
            }
        }
        template <typename Op>
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
                    cur = cur->left_;
                }
                if (!st.empty())
                {
                    cur = st.top();
                    if (cur->right_ && cur->right_ != last)
                    {
                        cur = cur->right_;
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
        template <typename Op>
        void pre_order_impl_recursion(const tree_node *rt, Op &op) const // 递归版先序遍历实现
        {
            if (!rt)
            {
                return;
            }
            op(rt);
            pre_order_impl_recursion(rt->left_, op);
            pre_order_impl_recursion(rt->right_, op);
        }
        template <typename Op>
        void in_order_impl_recursion(const tree_node *rt, Op &op) const // 递归版中序遍历实现
        {
            if (!rt)
            {
                return;
            }
            in_order_impl_recursion(rt->left_, op);
            op(rt);
            in_order_impl_recursion(rt->right_, op);
        }
        template <typename Op>
        void post_order_impl_recursion(const tree_node *rt, Op &op) const // 递归版后序遍历实现
        {
            if (!rt)
            {
                return;
            }
            post_order_impl_recursion(rt->left_, op);
            post_order_impl_recursion(rt->right_, op);
            op(rt);
        }

        template <typename Op>
        void level_order_impl(const tree_node *rt, Op &op) const // 层序遍历，使用队列
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
                if (tmp->left_)
                {
                    q.push(tmp->left_);
                }
                if (tmp->right_)
                {
                    q.push(tmp->right_);
                }
                q.pop();
            }
        }

        template <typename Op>
        void pre_order_impl_iter(const tree_node *rt, Op &op) const // 迭代版本先序遍历实现
        {
            stack<const tree_node *> st;
            const tree_node *cur = rt;
            while (cur || !st.empty())
            {
                while (cur)
                {
                    if (cur->right_)
                    {
                        st.push(cur->right_);
                    }
                    op(cur);
                    cur = cur->left_;
                }
                if (!st.empty())
                {
                    cur = st.top();
                    st.pop();
                }
            }
        }
        template <typename Op>
        void in_order_impl_iter(const tree_node *rt, Op &op) const // 迭代版本中序遍历实现
        {
            stack<const tree_node *> st;
            const tree_node *cur = rt;
            while (cur || !st.empty())
            {
                while (cur)
                {
                    st.push(cur);
                    cur = cur->left_;
                }
                if (!st.empty())
                {
                    cur = st.top()->right_;
                    op(st.top());
                    st.pop();
                }
            }
        }
        template <typename Op>
        void post_order_impl_iter(const tree_node *rt, Op &op) const // 迭代版后序遍历实现
        {
            stack<const tree_node *> st;
            const tree_node *cur = rt;
            const tree_node *last = nullptr;
            while (cur || !st.empty())
            {
                while (cur)
                {
                    st.push(cur);
                    cur = cur->left_;
                }
                if (!st.empty())
                {
                    cur = st.top();
                    if (cur->right_ && cur->right_ != last)
                    {
                        cur = cur->right_;
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

        void destroy() // 后序，迭代地析构所有节点
        {
            post_order([](tree_node *n) -> void
                       { delete n; });
        }

        size_t get_height(const tree_node *rt) const
        {
            if (!rt)
            {
                return 0;
            }
            return 1 + max(get_height(rt->left_), get_height(rt->right_));
        }

        tree_node *build_tree(const vector<T> &preorder, const vector<T> &inorder, int pre_begin, int in_begin, int length)
        {
            if (length == 0)
            {
                return nullptr;
            }
            tree_node *rt = new tree_node(preorder[pre_begin]);
            int rt_idx = in_begin;
            while (inorder[rt_idx] != rt->val_)
            {
                rt_idx++;
            }

            rt->left_ = build_tree(preorder, inorder, pre_begin + 1, in_begin, rt_idx - in_begin);
            rt->right_ = build_tree(preorder, inorder, pre_begin + 1 + rt_idx - in_begin, 1 + rt_idx, length - 1 - rt_idx + in_begin);

            return rt;
        }

    public:
        struct recursive_t // 递归标签
        {
        }; // 使用递归方式
        struct iterative_t // 迭代标签
        {
        }; // 使用迭代方式

        binary_tree() : root_(nullptr) {} // 空树
        binary_tree(const binary_tree &other) = delete;
        binary_tree &operator=(const binary_tree &other) = delete;

        binary_tree(const vector<T> &preorder, const vector<T> &inorder) // 前序+中序构造，需要调用者保证合法
        {
            root_ = build_tree(preorder, inorder, 0, 0, preorder.size());
        }

        template <typename U = T, typename std::enable_if<std::is_same<U, int>::value, int>::type dummy = 0>
        binary_tree(int n) // 对于值类型为int的树特化一个构造(用于作业要求)
        {
            (void)dummy; // 防止编译器警告
            auto v = vector<tree_node *>(n + 1, nullptr);
            for (int i = 1; i <= n; i++)
            {
                v[i] = new tree_node(i);
            }
            for (int i = 1; i <= n; i++)
            {
                int l, r;
                std::cin >> l >> r;
                if (l != -1)
                {
                    v[i]->left_ = v[l];
                }
                if (r != -1)
                {
                    v[i]->right_ = v[r];
                }
            }
            root_ = v[1];
        }
        ~binary_tree() // 后序遍历，逐个析构
        {
            destroy();
        }

#pragma region 非const遍历接口
        template <typename Operation_type>
        void pre_order(Operation_type &&op, recursive_t) { pre_order_impl_recursion(root_, op); } // 递归先序,操作类必须能接受tree_node*
        template <typename Operation_type>
        void pre_order(Operation_type &&op, iterative_t) { pre_order_impl_iter(root_, op); } // 迭代先序,操作类必须能接受tree_node*
        template <typename Operation_type>
        void pre_order(Operation_type &&op) { pre_order_impl_iter(root_, op); } // 默认迭代先序,操作类必须能接受tree_node*

        template <typename Operation_type>
        void in_order(Operation_type &&op, recursive_t) { in_order_impl_recursion(root_, op); } // 递归中序,操作类必须能接受tree_node*
        template <typename Operation_type>
        void in_order(Operation_type &&op, iterative_t) { in_order_impl_iter(root_, op); } // 迭代中序,操作类必须能接受tree_node*
        template <typename Operation_type>
        void in_order(Operation_type &&op) { in_order_impl_iter(root_, op); } // 默认迭代中序,操作类必须能接受tree_node*

        template <typename Operation_type>
        void post_order(Operation_type &&op, recursive_t) { post_order_impl_recursion(root_, op); } // 递归后序,操作类必须能接受tree_node*
        template <typename Operation_type>
        void post_order(Operation_type &&op, iterative_t) { post_order_impl_iter(root_, op); } // 迭代后序,操作类必须能接受tree_node*
        template <typename Operation_type>
        void post_order(Operation_type &&op) { post_order_impl_iter(root_, op); } // 默认迭代后序,操作类必须能接受tree_node*

        template <typename Operation_type>
        void level_order(Operation_type &&op) { level_order_impl(root_, op); } // 层序,操作类必须能接受tree_node*
#pragma endregion

#pragma region const遍历接口
        template <typename Operation_type>
        void pre_order(Operation_type &&op, recursive_t) const { pre_order_impl_recursion(root_, op); } // 递归先序,操作类必须能接受const tree_node*
        template <typename Operation_type>
        void pre_order(Operation_type &&op, iterative_t) const { pre_order_impl_iter(root_, op); } // 迭代先序,操作类必须能接受const tree_node*
        template <typename Operation_type>
        void pre_order(Operation_type &&op) const { pre_order_impl_iter(root_, op); } // 默认迭代先序,操作类必须能接受const tree_node*

        template <typename Operation_type>
        void in_order(Operation_type &&op, recursive_t) const { in_order_impl_recursion(root_, op); } // 递归中序,操作类必须能接受const tree_node*
        template <typename Operation_type>
        void in_order(Operation_type &&op, iterative_t) const { in_order_impl_iter(root_, op); } // 迭代中序,操作类必须能接受const tree_node*
        template <typename Operation_type>
        void in_order(Operation_type &&op) const { in_order_impl_iter(root_, op); } // 默认迭代中序,操作类必须能接受const tree_node*

        template <typename Operation_type>
        void post_order(Operation_type &&op, recursive_t) const { post_order_impl_recursion(root_, op); } // 递归后序,操作类必须能接受const tree_node*
        template <typename Operation_type>
        void post_order(Operation_type &&op, iterative_t) const { post_order_impl_iter(root_, op); } // 迭代后序,操作类必须能接受const tree_node*
        template <typename Operation_type>
        void post_order(Operation_type &&op) const { post_order_impl_iter(root_, op); } // 默认迭代后序,操作类必须能接受const tree_node*

        template <typename Operation_type>
        void level_order(Operation_type &&op) const { level_order_impl(root_, op); } // 层序,操作类必须能接受const tree_node*
#pragma endregion

        size_t size() const
        {
            size_t sz = 0;
            pre_order([&sz](const tree_node *) -> void
                      { sz++; });
            return sz;
        }

        size_t height() const
        {
            return get_height(root_);
        }

        tree_node *root() { return root_; }
        const tree_node *root() const { return root_; }
    };

} // namespace gyx

#endif
