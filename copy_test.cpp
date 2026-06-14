#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
using namespace std;

int main()
{
    ifstream ifs("test.exe", ios_base::binary);
    ofstream ofs("test_cp.exe", ios_base::binary);
    char c;
    while (ifs.get(c))
    {
        ofs << c;
    }
}
