#include <iostream>
#include <string>
using namespace std;

class Dog
{
private:
    int age;
    int weight;
    string name;

public:
    Dog() : age(0), weight(1), name("旺财") {}
    Dog(int a, int w, string n) : age(a), weight(w), name(n) {}

    inline void call()
    {
        cout << name << endl;
    }
    int get_age()
    {
        return age;
    }
    int get_weight()
    {
        return weight;
    }

    void introduce()
    {
        cout << "name:" << name << "  age:" << age << "  weight:" << weight << endl;
    }

    void set_age(int a)
    {
        age = a;
    }

    void set_weight(int a)
    {
        weight = a;
    }
    void set_name(string name_new)
    {
        name = name_new;
    }

    void bark()
    {
        cout << "wang" << endl;
    }
};

int main()
{
    Dog dog1;
    Dog dog2(1, 5, "大黄");
    dog1.introduce();
    dog2.call();

    dog2.set_name("大黑");
    dog2.call();

    dog1.set_age(100);
    dog1.set_weight(666);
    dog1.introduce();

    cout << dog2.get_age() << endl;
}
