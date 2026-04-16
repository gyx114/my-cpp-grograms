#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    string str1 = "you type in:" + str;
    cout << str1 << endl;
    return 0;
}
