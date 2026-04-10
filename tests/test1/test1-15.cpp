#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    for (;;)
    {
        cout << n << " ";
        n++;
        if (n == 10)
            break;
    }
    cout << endl;
    return 0;
}
