#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    queue<int> q;
    priority_queue<int> pq;

    vector<int> push1 = {5, 1, 4, 6};
    for (auto i : push1)
    {
        st.push(i);
        q.push(i);
        pq.push(i);
    }
    cout << "stack:" << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << endl;

    cout << "queue:" << endl;
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << endl;

    cout << "pq:" << endl;
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << endl;

    vector<int> push2 = {2, 3};
    for (auto i : push2)
    {
        st.push(i);
        q.push(i);
        pq.push(i);
    }
    cout << "stack:" << endl;
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << endl;

    cout << "queue:" << endl;
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    cout << endl;

    cout << "pq:" << endl;
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;
    pq.pop();
    cout << endl;
}
