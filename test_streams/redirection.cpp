#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ofstream fout("tst.out");
    auto p_cout_old = cout.rdbuf(fout.rdbuf()); // 把cout的缓冲区定向到文件
    string word;
    while (cin >> word)
    {
        cout << word << endl;
    }
    cout.rdbuf(p_cout_old); // 定向回来
    cout << "changed" << endl;
    cin.clear();
    cin >> word;
    cout << word << endl;

    fout.close();

    ifstream fin("tst.out");
    auto p_cin_old = cin.rdbuf(fin.rdbuf());

    while (cin >> word)
    {
        cout << word << '\t';
    }
    cout << endl;

    cin.rdbuf(p_cin_old);
    cin >> word;
    cout << word << endl;
}
