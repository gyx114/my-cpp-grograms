#include <stack>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    stack<string> s;
    string str;
    cin >> str; // 从键盘输入一个字符串
                // 将字符串的每个元素顺序压入栈中
    string tmp;
    for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
    {
        auto c = *iter;
        if (c != ',')
        {
            tmp += c;
        }
        else
        {
            s.push(move(tmp));
            tmp.clear();
        }
    }
    if (!tmp.empty())
    {
        s.push(move(tmp));
        tmp.clear();
    }

    // 将栈中的元素顺序弹出并输出
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
