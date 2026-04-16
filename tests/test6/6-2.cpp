#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    cout << &v << " " << &v[0] << endl;
    int a[] = {1, 2, 3, 4, 5};
    ;
    cout << &a << " " << &a[0] << endl;

    return 0;
}
