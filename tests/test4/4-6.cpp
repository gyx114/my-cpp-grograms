#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec = {103, 315, 403, 1224, 826};
    cout << "the size of a vector object: " << sizeof(vec) << endl;
    cout << "content starting from the address of vec:" << endl;
    const int *vec_ptr = (const int *)&vec;
    for (unsigned long i = 0; i < sizeof(vec) / 4 + vec.size(); i++)
    {
        cout << &vec_ptr[i] << ": " << vec_ptr[i] << endl;
    }

    cout << "content starting from the address of vec[0]:" << endl;
    const int *vec0_ptr = &vec[0];
    for (unsigned long i = 0; i < vec.size(); i++)
    {
        cout << &vec0_ptr[i] << ": " << vec0_ptr[i] << endl;
    }
    return 0;
}
