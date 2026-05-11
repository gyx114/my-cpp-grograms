#include <bits/stdc++.h>
using namespace std;

class lst
{
public:
    int val;
    lst *next;
    lst *pre;
    lst(int v = 0, lst *n = nullptr, lst *p = nullptr) : val(v), next(n), pre(p) {}
};
// 双向链表，用于管理
// 让访问的key挪到tail
// head处的key就是最久不使用的

class LRUCache
{
private:
    unordered_map<int, int> mp;         // 功能部件，提供o1查找
    unordered_map<int, lst *> key2node; // 控制部件，根据key映射到双向链表
    int capa;
    int cnt;
    lst *dummy;
    lst *tail;
    void mv_to_tail(int key)
    {
        auto nd = key2node[key];
        if (tail != nd)
        {
            nd->pre->next = nd->next;
            nd->next->pre = nd->pre;
            tail->next = nd;
            nd->pre = tail;
            nd->next = nullptr;
            tail = nd;
        }
    }

public:
    LRUCache(int capacity) : capa(capacity), cnt(0), dummy(new lst()), tail(dummy)
    {
    }

    int get(int key)
    {
        if (mp.count(key))
        {
            mv_to_tail(key);
            return mp[key];
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {

        if (mp.count(key))
        {
            mp[key] = value;
            mv_to_tail(key);
        }
        else
        {
            auto tmp = new lst(key, nullptr, tail);
            tail->next = tmp;
            tail = tmp;
            cnt++;
            if (cnt > capa)
            {
                auto n = dummy->next->next;

                // 及时erase头部key
                mp.erase(dummy->next->val);
                key2node.erase(dummy->next->val);

                delete dummy->next; // 防泄漏

                dummy->next = n;
                dummy->next->pre = dummy;
                cnt--;
            }

            // 添加新key
            mp[key] = value;
            key2node[key] = tmp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
