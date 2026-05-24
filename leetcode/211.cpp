#include <bits/stdc++.h>
using namespace std;

// 利用前缀树

// 前缀树节点,26个叉
class tree_26
{
public:
    bool is_end;              // 是否是某个字符串的结尾
    vector<tree_26 *> childs; // 子节点，0-25代表a-z
    tree_26(char c = -1) : is_end(false), childs(vector<tree_26 *>(26, nullptr)) {}
};

class Trie
{
public:
    tree_26 *root;
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
    bool search(tree_26 *rt, string word, int beg)
    {

        auto tmp = rt;
        for (int i = beg; i < word.size(); i++)
        {
            auto wordi = word[i];
            if (wordi == '.')
            {
                if (i == word.size() - 1)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        if (tmp->childs[j] && tmp->childs[j]->is_end)
                        {
                            return true;
                        }
                    }
                    return false;
                }
                for (auto *chi : tmp->childs)
                {
                    if (chi && search(chi, word, i + 1))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                if (!tmp->childs[wordi - 'a'])
                {
                    return false;
                }
                tmp = (tmp->childs)[wordi - 'a'];
            }
            if (i == word.size() - 1)
            {
                return tmp->is_end;
            }
        }
        return true;
    }
};

class WordDictionary
{
public:
    Trie trie;
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        trie.insert(word);
    }

    bool search(string word)
    {
        return trie.search(trie.root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
