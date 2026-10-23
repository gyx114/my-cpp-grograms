#include <iostream>
#include "../my_stl/queue.hpp"

using namespace gyx;
int main()
{
    int n;
    std::cin >> n;
    queue<int, vector<int>> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (q.size() >= 2)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    std::cout << q.front();
}
