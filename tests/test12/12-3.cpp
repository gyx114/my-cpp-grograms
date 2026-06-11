#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Dog
{
private:
    double weight;
    int age;

public:
    Dog(double w = 0.0, int a = 0) : weight(w), age(a) {}

    void set(double w, int a)
    {
        weight = w;
        age = a;
    }
    void show() { cout << "Weight: " << weight << ", Age: " << age << endl; }

    void saveText(const string &filename)
    {
        ofstream ofs(filename);
        ofs << weight << " " << age;
        ofs.close();
    }

    void loadText(const string &filename)
    {
        ifstream ifs(filename);
        ifs >> weight >> age;
        ifs.close();
    }

    void saveBin(const string &filename)
    {
        ofstream ofs(filename, ios::binary);
        ofs.write(reinterpret_cast<char *>(this), sizeof(Dog));
        ofs.close();
    }

    void loadBin(const string &filename)
    {
        ifstream ifs(filename, ios::binary);
        ifs.read(reinterpret_cast<char *>(this), sizeof(Dog));
        ifs.close();
    }
};

int main()
{
    Dog dog1(5.0, 10);
    Dog dog2;

    // 文本
    dog1.saveText("dog_text.txt");
    dog2.loadText("dog_text.txt");
    cout << "Text: ";
    dog2.show();

    // 二进制
    dog1.saveBin("dog_bin.dat");
    dog2.loadBin("dog_bin.dat");
    cout << "Binary: ";
    dog2.show();

    return 0;
}
