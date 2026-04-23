#include <iostream>
using namespace std;

// 哺乳动物类 Mammal
class Mammal
{
public:
    Mammal() { cout << "Mammal 构造函数调用" << endl; }
    ~Mammal() { cout << "Mammal 析构函数调用" << endl; }
};

// 狗类 Dog，公有继承 Mammal
class Dog : public Mammal
{
public:
    Dog() { cout << "Dog 构造函数调用" << endl; }
    ~Dog() { cout << "Dog 析构函数调用" << endl; }
};

int main()
{
    Dog d; // 创建 Dog 对象
    return 0;
}
