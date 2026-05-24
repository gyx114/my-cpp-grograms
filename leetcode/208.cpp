#include <bits/stdc++.h>
using namespace std;
class tree_26
{
public:
    bool is_end;              // 是否是某个字符串的结尾
    vector<tree_26 *> childs; // 子节点，0-25代表a-z
    tree_26(char c = -1) : is_end(false), childs(vector<tree_26 *>(26, nullptr)) {}
};

class Trie
{
private:
    tree_26 *root;

public:
    Trie()
    {
        root = new tree_26();
    }

    void insert(string word)
    {
        auto tmp = root;
        for (int i = 0; i < word.size(); i++)
        {
            auto wordi = word[i];
            if (!tmp->childs[wordi - 'a'])
            {
                auto t = new tree_26(false);
                (tmp->childs)[wordi - 'a'] = t;
            }
            tmp = (tmp->childs)[wordi - 'a'];
            if (i == word.size() - 1)
            {
                tmp->is_end = true;
            }
        }
    }

    bool search(string word)
    {
        auto tmp = root;
        for (int i = 0; i < word.size(); i++)
        {
            auto wordi = word[i];
            if (!tmp->childs[wordi - 'a'])
            {
                return false;
            }
            tmp = (tmp->childs)[wordi - 'a'];
            if (i == word.size() - 1)
            {
                return tmp->is_end;
            }
        }
        return true;
    }

    bool startsWith(string prefix)
    {

        auto tmp = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            auto pi = prefix[i];
            if ((tmp->childs)[pi - 'a'])
            {
                tmp = (tmp->childs)[pi - 'a'];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
