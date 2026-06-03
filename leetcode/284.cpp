#include <bits/stdc++.h>
using namespace std;

class Iterator
{
    struct Data;
    Data *data;

public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);

    // Returns the next element in the iteration.
    int next();

    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

class PeekingIterator : public Iterator
{
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        auto tmp = *this; // next接口会使迭代器右移，为了避免修改当前迭代器，做一个拷贝
        return tmp.next();
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        return Iterator::next();
    }

    bool hasNext() const
    {
        return Iterator::hasNext();
    }
};
