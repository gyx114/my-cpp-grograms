#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
public:
    priority_queue<int, vector<int>, less<int>> lft;
    priority_queue<int, vector<int>, greater<int>> rht;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (!lft.empty() && num >= lft.top())
        {
            rht.push(num);
        }
        else
        {
            lft.push(num);
        }
        if (lft.size() - rht.size() == 2)
        {
            rht.push(lft.top());
            lft.pop();
        }
        else if (-lft.size() + rht.size() == 2)
        {
            lft.push(rht.top());
            rht.pop();
        }
    }

    double findMedian()
    {
        if (lft.size() == rht.size())
        {
            return (lft.top() + rht.top()) / 2.0;
        }
        return lft.size() > rht.size() ? lft.top() : rht.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
