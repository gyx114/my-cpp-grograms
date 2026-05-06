#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        unordered_set<char> st1 = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
        unordered_set<char> st2 = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
        int l = 0;
        int r = s.length() - 1;
        while (l < r)
        {
            if (!st1.count(s[l]))
            {
                l++;
                continue;
            }
            if (!st1.count(s[r]))
            {
                r--;
                continue;
            }
            if (st2.count(s[l]))
            {
                s[l] += ('a' - 'A');
            }
            if (st2.count(s[r]))
            {
                s[r] += ('a' - 'A');
            }
            if (!(s[l] == s[r]))
            {
                return false;
            }
            else
            {
                l++;
                r--;
            }
        }
        return true;
    }
};
