#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        // const char *p = haystack.c_str();
        // const char *q = needle.c_str();
        // const char *dest = strstr(p, q);
        // if (dest)
        // {

        //     return dest - haystack.c_str();
        // }
        // return -1;

        return haystack.find(needle);
    }
};
