#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> st;
        for (auto i : nums)
        {
            if (st.count(i))
            {
                return true;
            }
            else
            {
                st.insert(i);
            }
        }
        return false;
    }
};
