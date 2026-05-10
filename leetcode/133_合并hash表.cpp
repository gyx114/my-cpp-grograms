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
    unordered_map<Node *, Node *> visited;
    void dfs(Node *node, Node *newnode)
    {
        for (auto n : node->neighbors)
        {
            Node *tmp;
            if (visited.count(n))
            {
                tmp = visited[n];
                newnode->neighbors.push_back(tmp);
            }
            else
            {
                tmp = new Node(n->val);
                newnode->neighbors.push_back(tmp);
                visited[n] = tmp;
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
        visited[node] = newnode;
        dfs(node, newnode);
        return newnode;
    }
};
