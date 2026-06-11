#include <iostream>
#include <random>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, 10000000);
    for (int i = 0; i < 10; ++i)
    {
        int num = dist(gen);
        // 居中打印nums的值
        string num_str = to_string(num);
        int len = num_str.length();

        const int total_width = 80;
        int lft_space = (total_width - len) / 2;

        cout << setw(len + lft_space) << num_str << endl;
    }
}
