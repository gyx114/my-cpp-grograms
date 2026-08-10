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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return head;
        }
        auto ji = head;
        auto ou = head->next;
        auto tmp_ji = ji;
        auto tmp_ou = ou;
        int cnt = -1;
        ListNode *tmp = nullptr;
        if (ou && ou->next)
        {
            cnt = 3;
            tmp = ou->next;
        }
        while (tmp)
        {
            if (cnt % 2 == 1)
            {
                tmp_ji->next = tmp;
                tmp_ji = tmp_ji->next;
            }
            else
            {
                tmp_ou->next = tmp;
                tmp_ou = tmp_ou->next;
            }
            tmp = tmp->next;
            cnt++;
        }
        if (cnt % 2 == 0)
        {
            tmp_ou->next = nullptr;
        }
        tmp_ji->next = ou;
        return ji;
    }
};
