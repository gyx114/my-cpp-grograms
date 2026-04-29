#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> ans;
    string tmp;
    int cnt_of_point = 0;
    void backtrack(string &s, int begin)
    {
        if (cnt_of_point > 3 || begin >= s.length())
        {
            return;
        }
        else if (cnt_of_point == 3)
        {
            if (s.length() - begin > 3)
            {
                return;
            }
            else if (s.length() - begin == 1)
            {
                tmp.push_back(s[begin]);
                ans.push_back(tmp);
                tmp.pop_back();
                return;
            }
            else if (s.length() - begin == 2)
            {
                if (s[begin] != '0')
                {
                    tmp += s.substr(begin, 2);
                    ans.push_back(tmp);
                    tmp.pop_back();
                    tmp.pop_back();
                }
                return;
            }
            else
            {
                int num = 100 * (s[begin] - '0') + 10 * (s[begin + 1] - '0') + s[begin + 2] - '0';
                if (num >= 100 && num <= 255)
                {
                    tmp += s.substr(begin, 3);
                    ans.push_back(tmp);
                    tmp.pop_back();
                    tmp.pop_back();
                    tmp.pop_back();
                }
                return;
            }
        }
        else
        {
            for (int i = begin; i <= begin + 2 && i <= s.length() - 1; i++)
            {
                if (s[begin] == '0')
                {
                    tmp.push_back(s[begin]);
                    tmp.push_back('.');
                    cnt_of_point++;

                    backtrack(s, begin + 1);

                    cnt_of_point--;
                    tmp.pop_back();
                    tmp.pop_back();
                    break;
                }
                else
                {
                    if (i == begin)
                    {
                        tmp.push_back(s[i]);
                        tmp.push_back('.');
                        cnt_of_point++;

                        backtrack(s, i + 1);

                        cnt_of_point--;
                        tmp.pop_back();
                        tmp.pop_back();
                    }
                    if (i == begin + 1)
                    {
                        tmp += {s[i - 1], s[i], '.'};
                        cnt_of_point++;

                        backtrack(s, i + 1);

                        cnt_of_point--;
                        tmp.pop_back();
                        tmp.pop_back();
                        tmp.pop_back();
                    }
                    if (i == begin + 2)
                    {
                        int num = 100 * (s[begin] - '0') + 10 * (s[begin + 1] - '0') + s[begin + 2] - '0';
                        if (num >= 100 && num <= 255)
                        {
                            tmp += s.substr(begin, 3);
                            tmp += '.';
                            cnt_of_point++;

                            backtrack(s, i + 1);

                            cnt_of_point--;
                            tmp.pop_back();
                            tmp.pop_back();
                            tmp.pop_back();
                            tmp.pop_back();
                        }
                    }
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        backtrack(s, 0);
        return ans;
    }
};
