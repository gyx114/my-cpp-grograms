
#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
    T data;

public:
    Node<T> *next;
    Node();
    Node(const T &data, Node<T> *nt = 0);
    //	Node(T data, Node<T>* n = NULL);
    T &getData();
};

template <class T>
Node<T>::Node()
{
    data = T();
    next = nullptr;
}

template <class T>
Node<T>::Node(const T &d, Node<T> *nt)
{
    data = d;
    next = nt;
}

template <class T>
T &Node<T>::getData()
{
    return data;
}

template <class T>
class LinkedList
{
protected:
    Node<T> *front, *rear; // 表头和表尾指针
    int size;              // 表中元素个数

public:                                 // 外部接口
    LinkedList();                       // 构造函数
    LinkedList(const LinkedList<T> &L); // 复制构造函数
    ~LinkedList();                      // 析构函数

    int getSize() const;  // 返回链表中元素个数
    bool isEmpty() const; // 链表是否为空
    void clear();         // 清空链表：释放所有节点的内存空间
    void display();

    void insertFront(const T &item);       // 在表头节点front之后插入节点
    void insertRear(const T &item);        // 在链表尾节点rear之前插入节点
    void insertAt(int idx, const T &item); // 在idx位置插入节点

    void deleteFront();     // 删除头节点
    void deleteAt(int idx); // 删除idx位置节点
};

// 构造函数
template <class T>
LinkedList<T>::LinkedList()
{
    front = new Node<T>(); // 指向新建节点，实际建立一个空的头node结点和尾节点
    rear = new Node<T>();
    front->next = rear;
    size = 0; // 不计算front和rear节点
}

// 析构函数
template <class T>
LinkedList<T>::~LinkedList()
{
    clear();      // 清空释放当前链表
    delete front; // 释放头指针所指节点
    delete rear;  // 释放尾指针所指节点
}

// 返回链表中元素个数
template <class T>
int LinkedList<T>::getSize() const
{
    return size;
}

// 链表是否为空
template <class T>
bool LinkedList<T>::isEmpty() const
{
    return (size == 0);
}

// 清空链表内容：释放所有节点的内存空间
template <class T>
void LinkedList<T>::clear()
{
    Node<T> *temp;
    while (front->next != rear)
    {
        temp = front->next;
        front->next = temp->next;
        delete temp;
    }
    size = 0;
}

template <class T>
void LinkedList<T>::display()
{ // 输出链表
    cout << "List: ";

    Node<T> *temp = front->next;
    while (temp != rear)
    {
        cout << temp->getData() << " ";
        temp = temp->next;
    }

    cout << endl;
}

// 在front节点后插入值
template <class T>
void LinkedList<T>::insertFront(const T &item)
{
    Node<T> *newNode = new Node<T>(item, front->next);
    front->next = newNode;
    size++;
}

// 在链表尾节点之前插入节点
template <class T>
void LinkedList<T>::insertRear(const T &item)
{
    Node<T> *temp = front;
    while (temp->next != rear)
    {
        temp = temp->next;
    }
    Node<T> *newNode = new Node<T>(item, rear);
    temp->next = newNode;
    size++;
}

// 在idx位置插入节点
template <class T>
void LinkedList<T>::insertAt(int idx, const T &item)
{
    if (idx < 1 || idx > size + 1)
        return;

    Node<T> *prev = front;
    for (int i = 0; i < idx - 1; i++)
    {
        prev = prev->next;
    }
    Node<T> *newNode = new Node<T>(item, prev->next);
    prev->next = newNode;
    size++;
}

// 删除头节点
template <class T>
void LinkedList<T>::deleteFront()
{
    if (front->next == rear)
        return;

    Node<T> *temp = front->next;
    front->next = temp->next;
    delete temp;
    size--;
}

// 删除idx位置的节点
template <class T>
void LinkedList<T>::deleteAt(int idx)
{
    if (idx < 1 || idx > size)
        return;

    Node<T> *prev = front;
    for (int i = 0; i < idx - 1; i++)
    {
        prev = prev->next;
    }
    Node<T> *temp = prev->next;
    prev->next = temp->next;
    delete temp;
    size--;
}

// 队列类定义
template <typename T>
class MyQueue : public LinkedList<T>
{
public:
    void push(T val)
    {
        this->insertRear(val);
    }

    T pop()
    {
        if (this->isEmpty())
        {
            cerr << "Queue is empty!" << endl;
            return T();
        }
        T val = this->front->next->getData();
        this->deleteFront();
        return val;
    }

    T peek()
    {
        if (this->isEmpty())
        {
            cerr << "Queue is empty!" << endl;
            return T();
        }
        return this->front->next->getData();
    }

    void display()
    {
        LinkedList<T>::display();
    }
};

int main()
{
    MyQueue<int> mq;
    for (int i = 0; i < 10; i++)
    {
        mq.push(i);
    }
    mq.pop();
    mq.push(mq.peek());
    mq.pop();
    mq.pop();
    mq.display();
    return 0;
}
