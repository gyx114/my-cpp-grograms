#include <bits/stdc++.h>
using namespace std;

string generateString(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    int trues[10000];
    int falses[10000];
    int num_true = 0;
    int num_false = 0;
    for (int i = 0; i < n; i++)
    {
        if (str1[i] == 'T')
        {
            trues[num_true++] = i;
        }
        else
        {
            falses[num_false++] = i;
        }
    }

    string s(m + n - 1, 'a');

    for (int i = 0; i < num_true; i++)
    {
        s.assign(str2, trues[i], m);
    }
}
