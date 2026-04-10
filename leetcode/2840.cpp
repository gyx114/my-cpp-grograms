#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;

bool judge(string s1, string s2)
{
    int len = s1.length();
    int len_ji = len / 2;
    int len_ou = len - len_ji;
    char s1_ou[100000], s1_ji[100000], s2_ou[100000], s2_ji[100000];
    s1_ou[len_ou] = 0;
    s2_ou[len_ou] = 0;
    s1_ji[len_ji] = 0;
    s2_ji[len_ji] = 0;

    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            s1_ou[i / 2] = s1[i];
            s2_ou[i / 2] = s2[i];
        }
        else
        {
            s1_ji[i / 2] = s1[i];
            s2_ji[i / 2] = s2[i];
        }
    }

    sort<char *>(s1_ou, s1_ou + len_ou);
    sort<char *>(s2_ou, s2_ou + len_ou);
    sort<char *>(s1_ji, s1_ji + len_ji);
    sort<char *>(s2_ji, s2_ji + len_ji);

    return !strcmp(s1_ou, s2_ou) && !strcmp(s1_ji, s2_ji);
}

int main()
{
    string s1, s2;

    cin >> s1;
    cin >> s2;
    if (judge(s1, s2))
    {
        cout << "true" << endl;
    }
    else
        cout << "false" << endl;
    return 0;
}

// 可以用二维数组，统计每个字母在奇数位和偶数位出现的次数
// 如果s1和s2的数组相同，则true

bool check(string s1, string s2)
{
    vector<vector<int>> v1(26, vector<int>(2, 0));
    vector<vector<int>> v2(26, vector<int>(2, 0));

    int len = s1.length();
    for (int i = 0; i < len; i++)
    {
        if (i % 2 == 0)
        {
            v1[s1[i] - 'a'][0]++;
            v2[s2[i] - 'a'][0]++;
        }
        else
        {
            v1[s1[i] - 'a'][1]++;
            v2[s2[i] - 'a'][1]++;
        }
    }

    return v1 == v2;
}
