#include <iostream>
using namespace std;
#include <cassert>
// 通用Stack模板定义
template <class T, int SIZE = 50>
class Stack
{
private:
    T list[SIZE];
    int top;

public:
    Stack();
    void push(const T &item);
    T pop();
    void clear();
    const T &peek() const;
    bool isEmpty() const;
    bool isFull() const;
};

// 通用Stack模板实现
template <class T, int SIZE>
Stack<T, SIZE>::Stack() : top(-1) {}

template <class T, int SIZE>
void Stack<T, SIZE>::push(const T &item)
{
    assert(!isFull());
    list[++top] = item;
}

template <class T, int SIZE>
T Stack<T, SIZE>::pop()
{
    assert(!isEmpty());
    return list[top--];
}

template <class T, int SIZE>
const T &Stack<T, SIZE>::peek() const
{
    assert(!isEmpty());
    return list[top];
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isEmpty() const
{
    return top == -1;
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isFull() const
{
    return top == SIZE - 1;
}

template <class T, int SIZE>
void Stack<T, SIZE>::clear()
{
    top = -1;
}

// 对bool类型的偏特化
template <int SIZE>
class Stack<bool, SIZE>
{
private:
    enum
    {
        UNIT_BITS = sizeof(unsigned) * 8,
        ARRAY_SIZE = (SIZE - 1) / UNIT_BITS + 1
    };
    unsigned list[ARRAY_SIZE];
    int top;

public:
    Stack();
    void push(bool item);
    bool pop();
    void clear();
    bool peek() const;
    bool isEmpty() const;
    bool isFull() const;
};

// bool特化版本的实现
template <int SIZE>
Stack<bool, SIZE>::Stack() : top(-1)
{
    clear();
}

template <int SIZE>
void Stack<bool, SIZE>::push(bool item)
{
    assert(!isFull());
    int index = ++top / UNIT_BITS;
    list[index] = (list[index] << 1) | (item ? 1 : 0);
}

template <int SIZE>
bool Stack<bool, SIZE>::pop()
{
    assert(!isEmpty());
    int index = top-- / UNIT_BITS;
    bool result = ((list[index] & 1) == 1);
    list[index] >>= 1;
    return result;
}

template <int SIZE>
void Stack<bool, SIZE>::clear()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        list[i] = 0;
    }
    top = -1;
}

template <int SIZE>
bool Stack<bool, SIZE>::peek() const
{
    assert(!isEmpty());
    int index = top / UNIT_BITS;
    return ((list[index] >> (top % UNIT_BITS)) & 1) == 1;
}

template <int SIZE>
bool Stack<bool, SIZE>::isEmpty() const
{
    return top == -1;
}

template <int SIZE>
bool Stack<bool, SIZE>::isFull() const
{
    return top == SIZE - 1;
}

#define sz 100

int main()
{
    Stack<bool, sz> stk;
    cout << "size of Stack<bool, 100>: " << sizeof(stk) << endl;
    for (int i = 0; i < sz; i++)
    {
        stk.push((bool)(i % 2));
    }
    for (int i = 0; i < sz; i++)
    {
        cout << i << "\t" << stk.pop() << endl;
    }
    return 0;
}
