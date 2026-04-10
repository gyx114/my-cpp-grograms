#include <iostream>
using namespace std;
int main()
{
    int *pt;
    {
        int a = 315;
        pt = &a;
    }
    cout << *pt << endl;
    return 0;
}
