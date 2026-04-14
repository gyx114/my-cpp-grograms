

// 大名鼎鼎的快慢指针

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(-1, head);
        ListNode *fast = &dummy;
        ListNode *slow = &dummy;
        int cnt = 0;
        while (fast->next != nullptr)
        {

            if (cnt >= n)
            {
                slow = slow->next;
            }

            fast = fast->next;
            cnt++;
        }
        slow->next = slow->next->next;
        return dummy.next;
    }
};
