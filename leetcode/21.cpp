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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        else
        {

            ListNode *head = new ListNode();
            ListNode *tmp = head;
            ListNode *tmp1 = list1;
            ListNode *tmp2 = list2;

            while (tmp1 || tmp2)
            {
                if (tmp1 == nullptr)
                {
                    tmp->next = tmp2;
                    break;
                }
                else if (tmp2 == nullptr)
                {
                    tmp->next = tmp1;
                    break;
                }
                else
                {
                    if (tmp1->val < tmp2->val)
                    {

                        tmp->next = tmp1;
                        tmp = tmp1;
                        tmp1 = tmp1->next;
                    }
                    else
                    {
                        tmp->next = tmp2;
                        tmp = tmp2;
                        tmp2 = tmp2->next;
                    }
                }
            }
            return head->next;
        }
    }
};
