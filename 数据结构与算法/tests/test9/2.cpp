#include <iostream>
#include "../my_stl/priority_queue.hpp"
#include "../my_stl/binary_tree.hpp"

using namespace gyx;

class root_cmp
{
public:
    bool operator()(const binary_tree<int> &a, const binary_tree<int> &b)
    {
        return a.root()->value() > b.root()->value();
    }
};

int main()
{
    vector<int> char_freq(26, 0);
    int c;
    while ((c = std::cin.get()) != EOF && c != '\n')
    {
        // 保证都是小写字母，过滤\r\n等
        if (c >= 'a' && c <= 'z')
            char_freq[c - 'a']++;
    }

    vector<binary_tree<int>> init;
    init.reserve(26);
    for (int i = 0; i < 26; i++)
    {
        if (char_freq[i])
        {
            init.emplace_back(char_freq[i]);
        }
    }

    priority_queue<binary_tree<int>, vector<binary_tree<int>>, root_cmp> pq(move(init));

    int length = 0; // 编码后长度
    if (pq.size() == 1)
    {
        length = pq.top().root()->value();
    }

    while (pq.size() > 1)
    {
        binary_tree<int> l(move(const_cast<binary_tree<int> &>(pq.top())));
        pq.pop();
        binary_tree<int> r(move(const_cast<binary_tree<int> &>(pq.top())));
        pq.pop();
        int l_val = l.root()->value();
        int r_val = r.root()->value();
        length += (l_val + r_val);
        pq.emplace(l_val + r_val, move(l), move(r));
    }
    std::cout << length << "\n";
}
