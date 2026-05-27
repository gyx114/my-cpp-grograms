#include <bits/stdc++.h>
using namespace std;
int main()
{
    multiset<string> st;
    string tmp;
    while (cin >> tmp)
    {
        if (st.count(tmp))
        {
            cout << tmp << "出现过,之前出现过" << st.count(tmp) << "次" << endl;
        }
        else
        {
            cout << tmp << "未出现过" << endl;
        }
        st.insert(tmp);
    }
}
