#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    unordered_map<int, Node *> val_to_node;
    // 为了防止回到上个节点，然后无限循环，需要visited来存已经走过的节点
    // 在遍历neighbors时，如果节点在visited中，不应对其dfs
    unordered_set<Node *> visited;
    void dfs(Node *node, Node *newnode)
    {
        for (auto n : node->neighbors)
        {
            Node *tmp;
            if (val_to_node.count(n->val))
            {
                tmp = val_to_node[n->val];
                newnode->neighbors.push_back(tmp);
            }
            else
            {
                tmp = new Node(n->val);
                newnode->neighbors.push_back(tmp);
                val_to_node[n->val] = tmp;
            }
            if (!visited.count(n))
            {
                visited.insert(n);
                dfs(n, tmp);
            }
        }
    }
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }
        Node *newnode = new Node(node->val);
        val_to_node[node->val] = newnode;
        visited.insert(node);
        dfs(node, newnode);
        return newnode;
    }
};
