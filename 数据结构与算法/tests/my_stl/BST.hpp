#ifndef GYX_MY_STL_BST_HPP
#define GYX_MY_STL_BST_HPP

#include "utility.hpp"
#include "vector.hpp"
#include "tree_traverse.hpp"
#include "pair.hpp"
#include <cstddef>
#include <type_traits>
#include <iostream>

namespace gyx
{

    template <typename T, typename Cmp = less<>>
    class BST
    {
    public:
        class tree_node
        {
            friend class BST;

        private:
            T val_;
            size_t lft_sz_;
            tree_node *left_;
            tree_node *right_;

        public:
            explicit tree_node(const T &v, size_t left_size = 0, tree_node *l = nullptr, tree_node *r = nullptr) : val_(v), lft_sz_(left_size), left_(l), right_(r) {}
            explicit tree_node(T &&v, size_t left_size = 0, tree_node *l = nullptr, tree_node *r = nullptr) : val_(move(v)), lft_sz_(left_size), left_(l), right_(r) {}
            ~tree_node() {}

            tree_node(const tree_node &other) = default;
            tree_node(tree_node &&other) noexcept : val_(move(other.val_)), lft_sz_(other.lft_sz_), left_(other.left_), right_(other.right_)
            {
                other.left_ = nullptr;
                other.right_ = nullptr;
                other.lft_sz_ = 0;
            }

            tree_node &operator=(const tree_node &other) = default;

            tree_node &operator=(tree_node &&other) noexcept
            {
                if (this != &other)
                {
                    val_ = move(other.val_);
                    lft_sz_ = other.lft_sz_;
                    left_ = other.left_;
                    right_ = other.right_;
                    other.left_ = nullptr;
                    other.right_ = nullptr;
                    other.lft_sz_ = 0;
                }
                return *this;
            }

            T &value() { return val_; }
            const T &value() const { return val_; }
            size_t left_size() const { return lft_sz_; }
            tree_node *left() { return left_; }
            tree_node *right() { return right_; }
            const tree_node *left() const { return left_; }
            const tree_node *right() const { return right_; }
        };

    private:
        tree_node *root_;
        Cmp cmp;

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

        template <typename U = T, typename std::enable_if<std::is_same<U, int>::value, int>::type = 0>
        pair<tree_node *, tree_node *> find_val_impl(const T &val, bool is_testinge) // 如果是实验使用，第二个参数应为true
        {                                                                            // 返回pair<prev,cur>找到cur应不为空
            int xor_sum = 0;
            tree_node *prev = nullptr;
            tree_node *cur = root_;
            while (cur)
            {
                xor_sum ^= cur->val_;
                if (cmp(val, cur->val_))
                {
                    prev = cur;
                    cur = cur->left_;
                }
                else if (cmp(cur->val_, val))
                {
                    prev = cur;
                    cur = cur->right_;
                }
                else
                { // 找到了
                    break;
                }
            }
            if (is_testing)
            {
                std::cout << xor_sum << "\n";
            }
            return pair<tree_node *, tree_node *>(prev, cur);
        }

        template <typename U = T, typename std::enable_if<std::is_same<U, int>::value, int>::type = 0>
        pair<tree_node *, tree_node *> find_idx_impl(size_t idx, bool is_testing) // 如果是实验使用，第二个参数应为true
        {                                                                         // 返回pair<prev,cur>
            int xor_sum = 0;
            tree_node *prev = nullptr;
            tree_node *cur = root_;
            while (cur)
            {
                xor_sum ^= cur->val_;
                if (idx < cur->left_size)
                {
                    prev = cur;
                    cur = cur->left_;
                }
                else if (idx > cur->left_size) // 向右
                {
                    idx = idx - cur->left_size - 1;
                    prev = cur;
                    cur = cur->right_;
                }
                else
                {
                    break;
                }
            }

            if (is_testing)
            {
                std::cout << xor_sum << "\n";
            }
            return pair<tree_node *, tree_node *>(prev, cur);
        }

        pair<tree_node *, tree_node *> find_val_impl(const T &val)
        {
            tree_node *prev = nullptr;
            tree_node *cur = root_;
            while (cur)
            {
                if (cmp(val, cur->val_))
                {
                    prev = cur;
                    cur = cur->left_;
                }
                else if (cmp(cur->val_, val))
                {
                    prev = cur;
                    cur = cur->right_;
                }
                else
                { // 找到了
                    break;
                }
            }

            return pair<tree_node *, tree_node *>(prev, cur);
        }

        pair<tree_node *, tree_node *> find_idx_impl(size_t idx)
        {
            tree_node *prev = nullptr;
            tree_node *cur = root_;
            while (cur)
            {
                if (idx < cur->left_size)
                {
                    prev = cur;
                    cur = cur->left_;
                }
                else if (idx > cur->left_size) // 向右
                {
                    idx = idx - cur->left_size - 1;
                    prev = cur;
                    cur = cur->right_;
                }
                else
                {
                    break;
                }
            }
            return pair<tree_node *, tree_node *>(prev, cur);
        }

        void erase_pointer_impl(tree_node *prev, tree_node *cur)
        {
            if (!cur)
            {
                return;
            }

            int sum_of_child = (int)((bool)(cur->left_)) + (int)((bool)(cur->right_));

            if (sum_of_child == 0) // 叶子结点，直接删
            {
                if (!prev)
                { // 单节点树，删成空树
                    delete cur;
                    root_ = nullptr;
                    return;
                }
                bool cur_is_on_left = cmp(cur->val_, prev->val_);
                delete cur;
                if (cur_is_on_left)
                {
                    prev->left_ = nullptr;
                    prev->left_size--;
                }
                else
                {
                    prev->right_ = nullptr;
                }
            }

            else if (sum_of_child == 1) // 有一个子树，直接接上
            {
                bool cur_subtree_left = cur->left_; // cur的子树在左还是在右
                if (!prev)
                {
                    root_ = cur_subtree_left ? cur->left_ : cur->right_;
                    delete cur;
                    return;
                }
                bool cur_is_on_left = cmp(cur->val_, prev->val_); // cur在prev的左还是右
                if (cur_is_on_left)
                {
                    prev->left_ = cur_subtree_left ? cur->left_ : cur->right_;
                    prev->left_size--;
                }
                else
                {
                    prev->right_ = cur_subtree_left ? cur->left_ : cur->right_;
                }
                delete cur;
            }

            else // 左右子树都有,用左子树最大节点来顶替
            {
                // 找左子树最大值
                tree_node *lft_child_max_prev = cur;
                tree_node *lft_child_max = cur->left_;
                while (lft_child_max->right_)
                {
                    lft_child_max_prev = lft_child_max;
                    lft_child_max = lft_child_max->right;
                }

                // 找到左子树最大节点后，直接和cur做swap虽然简单
                // 但对于禁止赋值类型，如实现map时T=pair<const K,V>
                // K是const的，swap时尝试移动/拷贝赋值都会报错
                // 所以，更通用的做法是把 "对cur赋值" 变成 "新建一个节点来顶替cur"

                tree_node *new_node_to_replace = new tree_node(lft_child_max->val_, cur->left_size, cur->left_, cur->right_); // 新建替代节点

                // 让cur的父节点连接替代节点，断掉cur和prev的联系
                if (!prev)
                {
                    root_ = new_node_to_replace;
                }
                else
                {
                    if (cmp(cur->val_, prev->val_))
                    {
                        prev->left_ = new_node_to_replace;
                    }
                    else
                    {
                        prev->right_ = new_node_to_replace;
                    }
                }
                delete cur;
                // 至此，我们用新节点把cur给替换了。下一步就是删除左子树最大节点
                // 但是要注意，当cur的左孩子没有右子树时，左子树最大节点就是左孩子，此时lft_child_max_prev是cur
                // 但是原来的cur已被新节点所替代，因此应该把lft_child_max_prev修正成新节点
                if (lft_child_max_prev == cur)
                {
                    lft_child_max_prev = new_node_to_replace;
                }

                // 递归调用，删除左子树最大节点
                erase_pointer_impl(lft_child_max_prev, lft_child_max);
            }
        }

    public:
        BST() : root_(nullptr), cmp(Cmp{}) {} // 空树
        explicit BST(Cmp cmp_) : cmp(move(cmp_)) {}
        BST(const BST &other) = delete;
        BST &operator=(const BST &other) = delete;

        BST(BST &&other) noexcept : root_(other.root_), cmp(move(other.cmp)) { other.root_ = nullptr; }
        BST &operator=(BST &&other) noexcept
        {
            if (this != &other)
            {
                swap(root_, other.root_);
                swap(cmp, other.cmp);
            }
            return *this;
        }

        BST(const T &val, size_t leftsize, BST &&l, BST &&r, Cmp cmp_ = {}) : // 左右子树构造，只接受右值
        {
            root_ = new tree_node(val, leftsize, l.root_, r.root_);
            l.root_ = nullptr;
            r.root_ = nullptr;
        }
        BST(T &&val, size_t leftsize, BST &&l, BST &&r, Cmp cmp_ = {}) // 左右子树构造
        {
            root_ = new tree_node(move(val), leftsize, l.root_, r.root_);
            l.root_ = nullptr;
            r.root_ = nullptr;
        }

        ~BST() // 后序遍历，逐个析构
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

        template <typename U = T, typename std::enable_if<std::is_same<U, int>::value, int>::type = 0>
        pair<tree_node *, bool> insert(const T &val, bool is_testing) // 如果是实验使用，第二个参数应为true
        {
            int xor_sum = 0;
            if (!root_) // 空树，直接当做根
            {
                root_ = new tree_node(val);
                if (is_testing)
                {
                    std::cout << xor_sum << '\n';
                }
                return pair<tree_node *, bool>(root_, true);
            }

            auto [prev, cur] = find_val_impl(val, is_testing);

            if (cur)
            { // 已存在
                return pair<tree_node *, bool>(cur, false);
            }

            if (cmp(prev->val_, val))
            {
                prev->right_ = new tree_node(val);
            }
            else
            {
                prev->left_ = new tree_node(val);
            }

            prev = nullptr;
            cur = root_;
            while (cur) // 再跑一趟，修正left_size
            {
                if (cmp(cur->val_, val))
                {
                    prev = cur;
                    cur = cur->right_;
                }
                else if (cmp(val, cur->val_))
                {
                    prev = cur;
                    cur->lft_sz_++;
                    cur = cur->left_;
                }
                else
                {
                    break;
                }
            }

            return pair<tree_node *, bool>(cur, true);
        }

        tree_node *find(const T &val, bool is_testing) // 如果是实验使用，第二个参数应为true
        {
            return find_val_impl(val, is_testing).second;
        }

        bool erase(const T &val, bool is_testing) // 如果是实验使用，第二个参数应为true
        {
            auto [prev, cur] = find_val_impl(val, is_testing);
            erase_pointer_impl(prev, cur);
            return cur;
        }

        tree_node *find_idx(size_t idx, bool is_testing) // 如果是实验使用，第二个参数应为true
        {
            return find_idx_impl(idx, is_testing).second;
        }

        bool erase_idx(size_t idx, bool is_testing) // 如果是实验使用，第二个参数应为true
        {
            auto [prev, cur] = find_idx(idx, is_testing);
            erase_pointer_impl(prev, cur);
            return cur;
        }

        pair<tree_node *, bool> insert(const T &val)
        {
            if (!root_) // 空树，直接当做根
            {
                root_ = new tree_node(val);
                return pair<tree_node *, bool>(root_, true);
            }

            auto [prev, cur] = find_val_impl(val);

            if (cur)
            { // 已存在
                return pair<tree_node *, bool>(cur, false);
            }

            if (cmp(prev->val_, val))
            {
                prev->right_ = new tree_node(val);
            }
            else
            {
                prev->left_ = new tree_node(val);
            }

            prev = nullptr;
            cur = root_;
            while (cur) // 再跑一趟，修正left_size
            {
                if (cmp(cur->val_, val))
                {
                    prev = cur;
                    cur = cur->right_;
                }
                else if (cmp(val, cur->val_))
                {
                    prev = cur;
                    cur->lft_sz_++;
                    cur = cur->left_;
                }
                else
                {
                    break;
                }
            }

            return pair<tree_node *, bool>(cur, true);
        }

        tree_node *find(const T &val)
        {
            return find_val_impl(val).second;
        }

        bool erase(const T &val)
        {
            auto [prev, cur] = find_val_impl(val);
            erase_pointer_impl(prev, cur);
            return cur;
        }

        tree_node *find_idx(size_t idx)
        {
            return find_idx_impl(idx).second;
        }

        bool erase_idx(size_t idx)
        {
            auto [prev, cur] = find_idx(idx);
            erase_pointer_impl(prev, cur);
            return cur;
        }
    };
} // namespace gyx

#endif
