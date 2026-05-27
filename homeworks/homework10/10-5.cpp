#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

template <typename container>
int solve(int n, int m)
{
    container cont;
    for (int i = 0; i < n; i++)
    {
        cont.push_back(i + 1);
    }
    auto it = cont.begin();
    while (cont.size() > 1)
    {
        for (int i = 0; i < m - 1; i++)
        {
            ++it;
            if (it == cont.end())
            {
                it = cont.begin();
            }
        }
        it = cont.erase(it);
        if (it == cont.end())
        {
            it = cont.begin();
        }
    }
    cout << cont.front() << endl;
    return cont.front();
}

int main()
{
    const int m = 5;
    const int n = 1e5;

    auto start = high_resolution_clock::now();
    int res1 = solve<vector<int>>(n, m);
    auto stop = high_resolution_clock::now();
    cout << "vector time: " << duration_cast<milliseconds>(stop - start).count() << "ms" << endl;

    start = high_resolution_clock::now();
    int res2 = solve<deque<int>>(n, m);
    stop = high_resolution_clock::now();
    cout << "deque time: " << duration_cast<milliseconds>(stop - start).count() << "ms" << endl;

    start = high_resolution_clock::now();
    int res3 = solve<list<int>>(n, m);
    stop = high_resolution_clock::now();
    cout << "list time: " << duration_cast<milliseconds>(stop - start).count() << "ms" << endl;
}
