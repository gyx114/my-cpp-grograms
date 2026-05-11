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
    ListNode *detectCycle(ListNode *head)
    {
        auto slow = head;
        auto fast = head;
        bool flag = false;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            return nullptr;
        }
        int loop_len = 0;
        do
        {
            fast = fast->next;
            loop_len++;
        } while (fast != slow);

        slow = fast = head;

        for (;;)
        {
            for (int i = 0; i < loop_len; i++)
            {
                fast = fast->next;
            }
            if (fast == slow)
            {
                break;
            }
            else
            {
                slow = slow->next;
                fast = slow;
            }
        }

        return slow;
    }
};
