#include <bits/stdc++.h>

using namespace std;

int reverse(int n)
{
    int ret = 0;
    while (n != 0)
    {
        ret = ret * 10 + n % 10;
        n /= 10;
    }
    return ret;
}

class students
{

public:
    int id;
    int score;
    students(int a, int b) : id(a), score(b) {};
};

struct stu_less

{
    bool operator()(const students &x, const students &y) const
    {
        return x.id < y.id;
    }
};
void f(students st)
{
}

int main()
{
    // set<int, less<int>> st1 = {1, 2, 3, 4, 5, 5, 4, 5};

    // for (auto i : st1)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // set<students, stu_less> st = {students(1, 100), students(2, 100), students(3, 99), students(99, 50)};
    // for (auto s : st)
    // {
    //     cout << s.id << "  " << s.score << endl;
    // }
    // stu_less f;
    // cout << f(students(1, 100), students(2, 100));

    // auto it = st.begin();

    // st1.equal_range(5);

    map<int, int> mp;
    mp.insert({1, 2});
    pair<int, int> pr = {6, 7};
    pr = {6, 100};
    mp.insert(pr);
    mp.insert({{3, 4}, {9, 10}});
    mp.insert({100, 200});
    mp.insert(map<int, int>::value_type(2, 9));
    mp.insert(pair(4, 8));
    mp.insert(make_pair(5, 10));
    mp.emplace(78, 91);


    for (auto i : mp)
    {
        cout << i.first << " " << i.second << endl;
    }
    students stud = {1, 10};
    f(students(1, 2));
    f({1, 2});
}
