#include <string>
using namespace std;
#include <queue>
#include <sstream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        string ans;
        bool has_next = true;
        while (has_next)
        {
            has_next = false;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto tmp = q.front();
                q.pop();
                if (tmp == nullptr)
                {
                    ans += "n ";
                }
                else
                {
                    ans += to_string(tmp->val) + ' ';

                    if (tmp->left || tmp->right)
                    {
                        has_next = true;
                    }
                    q.push(tmp->left);
                    q.push(tmp->right);
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        stringstream ss(data);
        queue<TreeNode *> q;
        TreeNode *root = new TreeNode(0);
        q.push(root);
        string tmp;

        ss >> tmp;
        if (tmp == "n")
        {
            return nullptr;
        }
        else
        {
            root->val = stoi(tmp);
        }

        while (true)
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto nd = q.front();
                q.pop();
                if (!(ss >> tmp))
                {
                    return root;
                }
                if (tmp == "n")
                {
                    if (nd)
                    {
                        nd->left = nullptr;
                    }
                }
                else
                {
                    nd->left = new TreeNode(stoi(tmp));
                    q.push(nd->left);
                }

                ss >> tmp;
                if (tmp == "n")
                {
                    if (nd)
                    {
                        nd->right = nullptr;
                    }
                }
                else
                {
                    nd->right = new TreeNode(stoi(tmp));
                    q.push(nd->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
