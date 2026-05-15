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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {

        auto tmp1 = headA;
        auto tmp2 = headB;
        if ((!tmp1) || (!tmp2))
        {
            return nullptr;
        }
        if (tmp1 == tmp2)
        {
            return tmp1;
        }
        int len1 = 0;
        int len2 = 0;
        while (tmp1)
        {
            len1++;
            tmp1 = tmp1->next;
        }
        while (tmp2)
        {
            len2++;
            tmp2 = tmp2->next;
        }

        if (len1 > len2)
        {
            swap(len1, len2);
            tmp1 = headB;
            tmp2 = headA;
        }
        else
        {
            tmp1 = headA;
            tmp2 = headB;
        }

        int diff = len2 - len1;
        for (int i = 0; i < diff; i++)
        {
            tmp2 = tmp2->next;
        }
        while (tmp1 && tmp2)
        {
            if (tmp1 == tmp2)
            {
                return tmp1;
            }
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        return nullptr;
    }
};
