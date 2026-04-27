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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy = ListNode(0, head);
        ListNode *pre = &dummy;
        ListNode *tmp = head;
        int val;
        int cnt = 0;
        while (pre != nullptr)
        {

            if (tmp)
            {
                if (tmp == head || tmp->val != val)
                {
                    if (cnt > 1)
                    {

                        pre->next = tmp;
                        cnt = 1;
                        val = tmp->val;
                        tmp = tmp->next;
                    }
                    else
                    {
                        cnt = 1;
                        if (tmp != head)
                        {
                            pre = pre->next;
                        }
                        val = tmp->val;
                        tmp = tmp->next;
                    }
                }

                else
                {
                    cnt++;
                    tmp = tmp->next;
                }
            }
            else
            {
                if (cnt > 1)
                {
                    pre->next = tmp;
                    cnt = 1;
                    break;
                }
                else
                {
                    break;
                }
            }
        }

        return dummy.next;
    }
};
