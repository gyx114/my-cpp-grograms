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
            T val_;             // 值
            tree_node *parent_; // 父节点(根节点为nullptr)
            size_t lft_sz_;     // 左子树节点数
            tree_node *left_;   // 左孩子
            tree_node *right_;  // 右孩子

        public:
            explicit tree_node(const T &v, tree_node *p = nullptr, size_t left_size = 0, tree_node *l = nullptr, tree_node *r = nullptr) : val_(v), parent_(p), lft_sz_(left_size), left_(l), right_(r) {}
            explicit tree_node(T &&v, tree_node *p = nullptr, size_t left_size = 0, tree_node *l = nullptr, tree_node *r = nullptr) : val_(move(v)), parent_(p), lft_sz_(left_size), left_(l), right_(r) {}
            ~tree_node() {}

            tree_node(const tree_node &other) = default;
            tree_node(tree_node &&other) noexcept : val_(move(other.val_)), parent_(other.parent_), lft_sz_(other.lft_sz_), left_(other.left_), right_(other.right_)
            {
                other.left_ = nullptr;
                other.right_ = nullptr;
                other.parent_ = nullptr;
                other.lft_sz_ = 0;
            }

            tree_node &operator=(const tree_node &other) = default;

            tree_node &operator=(tree_node &&other) noexcept
            {
                if (this != &other)
                {
                    val_ = move(other.val_);
                    parent_ = other.parent_;
                    lft_sz_ = other.lft_sz_;
                    left_ = other.left_;
                    right_ = other.right_;
                    other.left_ = nullptr;
                    other.right_ = nullptr;
                    other.parent_ = nullptr;
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
            tree_node *parent() { return parent_; }
            const tree_node *parent() const { return parent_; }
        };

    private:
        tree_node *root_;
        size_t size_;
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
        pair<tree_node *, tree_node *> find_val_impl(const T &val, bool is_testing, bool insert_mode = false) // 如果是实验使用，第二个参数应为true ; 如果是插入操作调用此函数，应传递true
        {                                                                                                     // 返回pair<prev,cur>,找到cur应不为空
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
                std::cout << (((insert_mode && cur) || (!insert_mode && !cur)) ? 0 : xor_sum) << "\n";
            }
            return pair<tree_node *, tree_node *>(prev, cur);
        }

        template <typename U = T, typename std::enable_if<std::is_same<U, int>::value, int>::type = 0>
        pair<tree_node *, tree_node *> find_idx_impl(size_t idx, bool is_testing) // 如果是实验使用，第二个参数应为true
        {                                                                         // 返回pair<prev,cur>
            int xor_sum = 0;
            if (idx == 0 || idx > size_)
            {
                if (is_testing)
                {
                    std::cout << "0\n";
                }
                return pair<tree_node *, tree_node *>(nullptr, nullptr);
            }
            idx--;
            tree_node *prev = nullptr;
            tree_node *cur = root_;
            while (cur)
            {
                xor_sum ^= cur->val_;
                if (idx < cur->lft_sz_)
                {
                    prev = cur;
                    cur = cur->left_;
                }
                else if (idx > cur->lft_sz_) // 向右
                {
                    idx = idx - cur->lft_sz_ - 1;
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
                std::cout << (cur ? xor_sum : 0) << "\n";
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
                if (idx < cur->lft_sz_)
                {
                    prev = cur;
                    cur = cur->left_;
                }
                else if (idx > cur->lft_sz_) // 向右
                {
                    idx = idx - cur->lft_sz_ - 1;
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

        void maintain_lft_sz(tree_node *cur, bool add_or_sub) // 维护cur的祖先的lft_sz,第二个参数如果为true则+1，否则-1
        {
            tree_node *tmp = cur->parent_;
            bool from_lft = ((tmp) && (tmp->left_ == cur));
            while (tmp)
            {
                if (from_lft)
                {
                    if (add_or_sub)
                    {
                        tmp->lft_sz_++;
                    }
                    else
                    {
                        tmp->lft_sz_--;
                    }
                }
                from_lft = ((tmp->parent_) && (tmp->parent_->left_ == tmp));
                tmp = tmp->parent_;
            }
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

                // 向上维护lft_sz
                maintain_lft_sz(cur, false);

                bool cur_is_on_left = prev->left_ == cur;
                delete cur;
                if (cur_is_on_left)
                {
                    prev->left_ = nullptr;
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
                    root_->parent_ = nullptr;
                    delete cur;
                    return;
                }

                // 维护lft_sz
                maintain_lft_sz(cur, false);

                bool cur_is_on_left = prev->left_ == cur; // cur在prev的左还是右
                if (cur_is_on_left)
                {
                    prev->left_ = cur_subtree_left ? cur->left_ : cur->right_;
                    prev->left_->parent_ = prev;
                }
                else
                {
                    prev->right_ = cur_subtree_left ? cur->left_ : cur->right_;
                    prev->right_->parent_ = prev;
                }
                delete cur;
            }

            else // 左右子树都有,用右子树最小节点来顶替
            {
                // 找右子树最小值
                tree_node *rgt_child_min = cur->right_;
                while (rgt_child_min->left_)
                {
                    rgt_child_min = rgt_child_min->left_;
                }

                // 找到右子树最小节点后，直接和cur做swap虽然简单
                // 但对于禁止赋值类型，如实现map时T=pair<const K,V>
                // K是const的，swap时尝试移动/拷贝赋值都会报错
                // 所以，更通用的做法是把 "对cur赋值" 变成 "新建一个节点来顶替cur"

                tree_node *new_node_to_replace = new tree_node(rgt_child_min->val_, prev, cur->lft_sz_, cur->left_, cur->right_); // 新建替代节点

                // 让cur的父节点连接替代节点，断掉cur和prev的联系
                if (!prev)
                {
                    root_ = new_node_to_replace;
                }
                else
                {
                    if (prev->left_ == cur)
                    {
                        prev->left_ = new_node_to_replace;
                    }
                    else
                    {
                        prev->right_ = new_node_to_replace;
                    }
                }
                // 让cur的孩子们连接新节点，让cur彻底被替代
                if (cur->left_)
                {
                    cur->left_->parent_ = new_node_to_replace;
                }
                if (cur->right_)
                {
                    cur->right_->parent_ = new_node_to_replace;
                }

                // 此时，cur彻底被替代，可以删了
                delete cur;

                // 至此，我们用新节点把cur给替换了。下一步就是删除右子树最小节点
                // 递归调用，删除右子树最小节点
                erase_pointer_impl(rgt_child_min->parent_, rgt_child_min);
            }
        }

    public:
        BST() : root_(nullptr), size_(0), cmp(Cmp{}) {} // 空树
        explicit BST(Cmp cmp_) : root_(nullptr), size_(0), cmp(move(cmp_)) {}
        BST(const BST &other) = delete;
        BST &operator=(const BST &other) = delete;

        BST(BST &&other) noexcept : root_(other.root_), size_(other.size_), cmp(move(other.cmp))
        {
            other.root_ = nullptr;
            other.size_ = 0;
        }
        BST &operator=(BST &&other) noexcept
        {
            if (this != &other)
            {
                swap(root_, other.root_);
                swap(size_, other.size_);
                swap(cmp, other.cmp);
            }
            return *this;
        }

        BST(const T &val, BST &&l, BST &&r, Cmp cmp_ = {}) : size_(l.size_ + r.size_ + 1), cmp(cmp_) // 左右子树构造，只接受右值
        {
            size_t leftsize = l.size();
            root_ = new tree_node(val, nullptr, leftsize, l.root_, r.root_);
            if (root_->left_)
            {
                root_->left_->parent_ = root_;
            }
            if (root_->right_)
            {
                root_->right_->parent_ = root_;
            }
            l.root_ = nullptr;
            r.root_ = nullptr;
        }
        BST(T &&val, BST &&l, BST &&r, Cmp cmp_ = {}) : size_(l.size_ + r.size_ + 1), cmp(cmp_) // 左右子树构造
        {
            size_t leftsize = l.size();
            root_ = new tree_node(move(val), nullptr, leftsize, l.root_, r.root_);
            if (root_->left_)
            {
                root_->left_->parent_ = root_;
            }
            if (root_->right_)
            {
                root_->right_->parent_ = root_;
            }
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
            return size_;
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
                size_++;
                if (is_testing)
                {
                    std::cout << xor_sum << '\n';
                }
                return pair<tree_node *, bool>(root_, true);
            }

            auto [prev, cur] = find_val_impl(val, is_testing, true);

            if (cur) // 已存在
            {
                return pair<tree_node *, bool>(cur, false);
            }

            if (cmp(prev->val_, val))
            {
                cur = prev->right_ = new tree_node(val, prev);
            }
            else
            {
                cur = prev->left_ = new tree_node(val, prev);
            }
            size_++;

            // 向上修正lft_sz
            maintain_lft_sz(cur, true);

            return pair<tree_node *, bool>(cur, true);
        }

        template <typename U = T, typename std::enable_if<std::is_same<U, int>::value, int>::type = 0>
        tree_node *find(const T &val, bool is_testing) // 如果是实验使用，第二个参数应为true
        {
            return find_val_impl(val, is_testing).second;
        }

        template <typename U = T, typename std::enable_if<std::is_same<U, int>::value, int>::type = 0>
        bool erase(const T &val, bool is_testing) // 如果是实验使用，第二个参数应为true
        {
            auto [prev, cur] = find_val_impl(val, is_testing);
            if (cur)
            {
                size_--;
            }
            erase_pointer_impl(prev, cur);
            return cur;
        }

        template <typename U = T, typename std::enable_if<std::is_same<U, int>::value, int>::type = 0>
        tree_node *find_idx(size_t idx, bool is_testing) // 如果是实验使用，第二个参数应为true
        {
            return find_idx_impl(idx, is_testing).second;
        }

        template <typename U = T, typename std::enable_if<std::is_same<U, int>::value, int>::type = 0>
        bool erase_idx(size_t idx, bool is_testing) // 如果是实验使用，第二个参数应为true
        {
            auto [prev, cur] = find_idx_impl(idx, is_testing);
            if (cur)
            {
                size_--;
            }
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

            if (cur) // 已存在
            {
                return pair<tree_node *, bool>(cur, false);
            }

            if (cmp(prev->val_, val))
            {
                cur = prev->right_ = new tree_node(val, prev);
            }
            else
            {
                cur = prev->left_ = new tree_node(val, prev);
            }
            size_++;

            // 向上修正lft_sz
            maintain_lft_sz(cur, true);

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
            auto [prev, cur] = find_idx_impl(idx);
            erase_pointer_impl(prev, cur);
            return cur;
        }
    };
} // namespace gyx

#endif
