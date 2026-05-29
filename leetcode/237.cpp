#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // void deleteNode(ListNode *node)
    // {
    //     /* 值前移*/
    //     ListNode *prepre = nullptr;
    //     auto pre = node;
    //     auto tmp = node->next;
    //     while (tmp)
    //     {
    //         pre->next = tmp;
    //         pre->val = tmp->val;
    //         prepre = pre;
    //         pre = tmp;
    //         tmp = tmp->next;
    //     }
    //     delete pre;
    //     prepre->next = nullptr;
    // }

    void deleteNode(ListNode *node)
    {
        // 把下一个节点值复制过来，然后删除下一个节点

        auto nxt = node->next;
        node->val = nxt->val;
        node->next = nxt->next;
        delete nxt;
    }
};
