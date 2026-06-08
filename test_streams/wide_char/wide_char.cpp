#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
using namespace std;

int main()
{
    system("chcp 65001 > nul");
    _setmode(_fileno(stdout), _O_U8TEXT);
    wstring str = L"这是一个中文字符串";
    wcout << str.substr(3, 2) << endl;
    return 0;
}
