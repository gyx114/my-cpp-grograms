#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        if (preorder == "#") // 只有一个空指针
        {
            return true;
        }

        if (preorder.front() == '#') // 根节点不能为空
        {
            return false;
        }

        bool is_root = true;
        istringstream ss(preorder);
        string token;
        getline(ss, token, ','); // 读第一个
        int cnt = 1;             // 给根节点留的初始槽位

        // 空节点(#)消耗1个槽位，非空节点消耗一个槽位，又产生两个槽位，净增1个槽位
        while (true)
        {
            string nextline;
            bool has_next_line = static_cast<bool>(getline(ss, nextline, ','));
            if (token != "#")
            {
                cnt++;
            }
            else
            {
                cnt--;
                if (cnt == 0 && has_next_line)
                {
                    return false;
                }
            }
            if (!has_next_line)
            {
                break;
            }
            token.swap(nextline);
        }
        return cnt == 0;
    }
};
