#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (auto s : tokens)
        {
            if (s == "+")
            {
                auto fst = st.top();
                st.pop();
                auto snd = st.top();
                st.pop();
                st.push(fst + snd);
            }
            else if (s == "-")
            {
                auto fst = st.top();
                st.pop();
                auto snd = st.top();
                st.pop();
                st.push(snd - fst);
            }
            else if (s == "*")
            {
                auto fst = st.top();
                st.pop();
                auto snd = st.top();
                st.pop();
                st.push(fst * snd);
            }
            else if (s == "/")
            {
                auto fst = st.top();
                st.pop();
                auto snd = st.top();
                st.pop();
                st.push(snd / fst);
            }
            else
            {
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
