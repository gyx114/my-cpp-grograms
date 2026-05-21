#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

// 求平方的函数
int square(int x)
{
    return x * x;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[6];

    // 从标准输入读入若干个实数，分别将它们的平方输出
    transform(a, a + 6,
              b, square);
    for (auto i : b)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
