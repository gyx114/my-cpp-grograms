#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int jinwei = 1;
        int tmp = 0;
        int remain = 0;
        int n = digits.size();
        int i = n - 1;
        while (jinwei != 0)
        {
            if (i == -1)
            {
                digits.insert(digits.begin(), jinwei);
                break;
            }
            tmp = digits[i] + jinwei;
            remain = tmp % 10;
            digits[i] = remain;
            jinwei = tmp / 10;
            i--;
        }
        return digits;
    }
};
