#include <iostream>
using namespace std;
class Mammal
{
protected:
    int age;
    bool gender;

public:
    Mammal(int a = 0, bool g = true) : age(a), gender(g) {}
    virtual ~Mammal() {}
    virtual void speak()
    {
        cout << "age:" << age << endl;
        cout << "gender:" << (gender ? "male" : "female") << endl;
    }
};

class Dog : public Mammal
{
private:
    string name;

public:
    Dog(int a = 0, bool g = true, string n = "旺财") : Mammal(a, g), name(n) {}
    ~Dog() override {}
    void speak() override
    {
        cout << "woof" << endl;
        Mammal::speak();
        cout << "name:" << name << endl;
    }
};

void f(Mammal &m)
{
    m.speak();
}

int main()
{
    Dog d1 = Dog(3, true, "大黄");
    Dog d2 = Dog();
    d1.speak();
    f(d2);
}
