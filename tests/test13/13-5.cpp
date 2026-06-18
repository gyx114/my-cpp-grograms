#include <iostream>
#include <memory>
using namespace std;

template <typename T>
class my_unique_ptr
{
private:
    T *p;

public:
    explicit my_unique_ptr(T *pp = nullptr) : p(pp) {}
    ~my_unique_ptr()
    {
        delete p;
    }

    my_unique_ptr(const my_unique_ptr &that) = delete;
    my_unique_ptr &operator=(const my_unique_ptr &that) = delete;

    my_unique_ptr(my_unique_ptr &&that) noexcept : p(that.p)
    {
        that.p = nullptr;
    }
    my_unique_ptr &operator=(my_unique_ptr &&that) noexcept
    {
        if (this != &that)
        {
            delete p;
            p = that.p;
            that.p = nullptr;
        }
        return *this;
    }

    T *release()
    {
        T *tmp = p;
        p = nullptr;
        return tmp;
    }

    void reset(T *pp = nullptr)
    {
        delete p;
        p = pp;
    }

    T *get() const
    {
        return p;
    }

    T &operator*() const
    {
        return *p;
    }

    T *operator->() const
    {
        return p;
    }
};

class A
{
    int id;

public:
    A(int i) : id(i)
    {
        cout << "object " << id << " is constructed" << endl;
    }
    ~A()
    {
        cout << "object " << id << " is deconstructed" << endl;
    }
};
int main()
{
    A *a1 = new A(1);
    A a2(2);
    A *a3 = new A(3);
    my_unique_ptr<A> a3_ptr(a3);
    delete a1;
}
