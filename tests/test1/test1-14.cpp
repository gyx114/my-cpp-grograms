#include <iostream>
#include <limits>
using namespace std;

enum T
{
    T1,
    T2,
    T3,
    T4
};

enum S
{
    S1,
    S2 = INT_MAX,
    S3,
    S4
};

enum R
{
    R1 = 3,
    R2 = 1,
    R3 = 5,
    R4
};

int main()
{
    T t = T1;
    S s = S1;
    R r = R1;
    cout << sizeof(t) << "\t" << sizeof(s) << "\t" << sizeof(r) << endl;

    cout << T1 << " " << T2 << " " << T3 << " " << T4 << endl;
    cout << S1 << " " << S2 << " " << S3 << " " << S4 << endl;
    cout << R1 << " " << R2 << " " << R3 << " " << R4 << endl;

    return 0;
}
