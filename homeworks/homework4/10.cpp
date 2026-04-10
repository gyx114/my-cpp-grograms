#include <iostream>
#include <string>
using namespace std;

class CPU
{
private:
    unsigned frequency : 12;
    unsigned wordlenth : 1;
    unsigned core : 2;
    unsigned chaoxiancheng : 1;

public:
    CPU() : frequency(0), wordlenth(0), core(0), chaoxiancheng(0) {}

    CPU(int a, int b, int c, int d) : frequency(a), wordlenth(b), core(c), chaoxiancheng(d) {}

    void print()
    {
        string wdl = wordlenth == 0 ? "32位" : "64位";
        string cor = core == 0 ? "单核" : (core == 1 ? "双核" : "四核");
        string chao = chaoxiancheng == 0 ? "不支持" : "支持";
        cout << "时钟频率:" << frequency << endl;
        cout << "字长:" << wdl << endl;
        cout << "核数:" << cor << endl;
        cout << "是否支持超线程:" << chao << endl;
    }
};

int main()
{
    CPU cpu1;
    CPU cpu2(2600, 1, 2, 1);

    cout << sizeof(cpu1) << endl;
    cpu1.print();

    cout << sizeof(cpu2) << endl;
    cpu2.print();
}
