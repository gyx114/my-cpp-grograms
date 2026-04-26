#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string simplifyPath(string path)
    {
        path.push_back('/');
        vector<string> st;
        string tmp;
        auto it = path.begin();
        auto pre = path.begin();

        while (it != path.end())
        {
            if (*it == '/' && *pre == '/')
            {
                if (it - pre > 1)
                {
                    tmp.assign(pre + 1, it);

                    if (tmp == ".")
                    {
                        ;
                    }
                    else if (tmp == "..")
                    {
                        if (!st.empty())
                        {
                            st.pop_back();
                        }
                    }
                    else
                    {
                        st.push_back(move(tmp));
                    }
                }

                pre = it;
                it++;
            }
            else
            {
                it++;
            }
        }

        string ans;

        for (auto s : st)
        {
            ans += "/";
            ans += s;
        }
        if (ans.empty())
        {
            ans = "/";
        }
        return ans;
    }
};
