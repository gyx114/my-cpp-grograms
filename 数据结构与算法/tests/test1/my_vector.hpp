#ifndef MY_VECTOR
#define MY_VECTOR

#include <stdexcept>

template <typename T>
class my_vector
{
private:
    T *arr;
    int n;

public:
    my_vector(int sz = 0, T init_val = (T)0) : n(sz)
    {
        arr = static_cast<T *>(new T[sz]);
        for (int i = 0; i < sz; i++)
        {
            arr[i] = init_val;
        }
    }

    T &operator[](int idx)
    {
        if (idx < 0 || idx >= n)
        {
            throw std::logic_error("下标越界！");
        }
        return arr[idx];
    }
    const T &operator[](int idx) const
    {
        if (idx < 0 || idx >= n)
        {
            throw std::logic_error("下标越界！");
        }
        return arr[idx];
    }

    int size() const
    {
        return n;
    }

    ~my_vector()
    {
        delete[] arr;
    }
};

#endif
