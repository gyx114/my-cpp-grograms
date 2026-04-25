#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
        {
            return head;
        }
        auto tmp = head;
        ListNode *pre = nullptr;
        int len = 0;
        while (tmp != nullptr)
        {
            len++;
            pre = tmp;
            tmp = tmp->next;
        }
        pre->next = head;
        k = k % len;

        tmp = head;
        pre = nullptr;
        for (int i = 0; i < len - k; i++)
        {
            pre = tmp;
            tmp = tmp->next;
        }
        pre->next = nullptr;
        return tmp;
    }
};
