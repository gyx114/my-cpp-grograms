#include <iostream>
using namespace std;

class Tree
{
    int ages;

public:
    Tree() : ages(0) {}
    Tree(int ag) : ages(ag) {}

    void grow(int years)
    {
        ages += years;
    }

    void age()
    {
        cout << ages << endl;
    }
};

int main()
{
    Tree tr1;
    Tree tr2(3);

    tr1.age();
    tr2.age();

    tr1.grow(666);
    tr1.age();
}
