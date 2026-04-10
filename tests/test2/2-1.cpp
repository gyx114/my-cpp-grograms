#include <iostream>
#include <string>
using namespace std;

class CPU
{
private:
    string brand;
    string model;
    double frequency;
    int cores;

public:
    CPU(string b, string m, double f, int c)
        : brand(b), model(m), frequency(f), cores(c) {}

    void display() const
    {
        cout << "CPU: " << brand << " " << model << " "
             << frequency << "GHz " << cores << "核" << endl;
    }
};

class Computer
{
private:
    CPU cpu;
    int ram;
    int storage;
    string gpu;

public:
    Computer(const CPU &c, int r, int s, const string &g)
        : cpu(c), ram(r), storage(s), gpu(g) {}

    void show() const
    {
        cout << "计算机配置：" << endl;
        cpu.display();
        cout << "内存: " << ram << "GB" << endl
             << "硬盘: " << storage << "GB" << endl
             << "显卡: " << gpu << endl
             << endl;
    }

    void upgradeRAM(int add)
    {
        ram += add;
        cout << "内存升级到: " << ram << "GB" << endl;
    }
};

int main()
{
    CPU cpu1("Intel", "i7-12700K", 3.6, 12);
    CPU cpu2("AMD", "Ryzen 9 7950X", 4.5, 16);

    Computer pc1(cpu1, 16, 512, "RTX 3060");
    Computer pc2(cpu2, 32, 2000, "RTX 4090");

    pc1.show();
    pc2.show();

    pc1.upgradeRAM(8);

    return 0;
}
