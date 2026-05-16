#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        vector<int> v1;
        vector<int> v2;
        int lft = 0;
        int len = 0;
        for (int i = 0; i <= version1.size(); i++)
        {
            if (i == version1.size() || version1[i] == '.')
            {
                v1.emplace_back(stoi(version1.substr(lft, len)));
                lft = i + 1;
                len = 0;
            }
            else
            {
                len++;
            }
        }
        lft = 0;
        len = 0;
        for (int i = 0; i <= version2.size(); i++)
        {
            if (i == version2.size() || version2[i] == '.')
            {
                v2.emplace_back(stoi(version2.substr(lft, len)));
                lft = i + 1;
                len = 0;
            }
            else
            {
                len++;
            }
        }
        int l1 = v1.size();
        int l2 = v2.size();
        int l = max(l1, l2);
        for (int i = 0; i < l; i++)
        {

            int n1 = i >= v1.size() ? 0 : v1[i];
            int n2 = i >= v2.size() ? 0 : v2[i];

            if (n1 < n2)
            {
                return -1;
            }
            else if (n1 > n2)
            {
                return 1;
            }
        }
        return 0;
    }
};
