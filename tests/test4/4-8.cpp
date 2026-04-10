#include <iostream>
using namespace std;
int main()
{
    int a1[1];
    int a2[1];
    float dummy = 3.15;
    int a3[1];
    int *aa1[3] = {a1, a2, a3};
    int aa2[3][1];
    int *b1 = new int[1];
    int *b2 = new int[1];
    // int *dummy2 = new int[5];
    int *b3 = new int[1];
    int *aa3[3] = {b1, b2, b3};

    cout << aa1[1] - aa1[0] << " " << aa1[2] - aa1[1] << endl;
    cout << aa2[1] - aa2[0] << " " << aa2[2] - aa2[1] << endl;
    cout << aa3[1] - aa3[0] << " " << aa3[2] - aa3[1] << endl;
    // cin >> dummy;
}
