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
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = new ListNode(0);
        slow->next = head;
        ListNode *fast = head;
        int cnt = 0;
        while (slow != fast)
        {
            if (fast == nullptr)
            {
                return false;
            }
            if (cnt % 2 == 0)
            {
                slow = slow->next;
            }
            fast = fast->next;
            cnt++;
        }
        return true;
    }
};
