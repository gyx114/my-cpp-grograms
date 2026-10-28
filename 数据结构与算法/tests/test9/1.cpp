#include "../my_stl/priority_queue.hpp"
#include <iostream>
using namespace gyx;

#define INSERT 1
#define DELETE 2
#define SORT 3

void one_op(priority_queue<int, vector<int>, greater<>> &pq)
{
    int op;
    std::cin >> op;
    switch (op)
    {
    case INSERT:
    {
        int num;
        std::cin >> num;
        pq.push(num);
        std::cout << pq.top() << "\n";
        break;
    }
    case DELETE:
    {
        pq.pop();
        std::cout << pq.top() << '\n';
        break;
    }
    case SORT:
    {
        int n;
        std::cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            std::cin >> v[i];
        }

        priority_queue<int, vector<int>, greater<>> q(move(v));
        while (q.size())
        {
            std::cout << q.top();
            if (q.size() != 1)
            {
                std::cout << " ";
            }
            q.pop();
        }
        std::cout << '\n';
        break;
    }

    default:
        break;
    }
}

int main()
{
    int n;
    std::cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }
    priority_queue<int, vector<int>, gyx::greater<>> pq(move(v));
    std::cout << pq.top() << "\n";

    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++)
    {
        one_op(pq);
    }
}
