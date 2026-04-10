#include <iostream>
using namespace std;

const int count = INT_MAX;
int main()
{
    int *a = new int[count];
    unsigned long long sum = 0;
    for (int i = 0; i < count; i++)
    {
        a[i] = i;
    }
    for (int i = 0; i < count; i++)
    {
        sum += a[i];
    }
    cout << sum << endl;
    return 0;
}
