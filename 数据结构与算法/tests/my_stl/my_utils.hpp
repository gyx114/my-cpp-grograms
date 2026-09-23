#ifndef MY_UTILS
#define MY_UTILS
// 去引用
template <typename T>
struct RemoveRef
{
    using type = T;
};

template <typename T>
struct RemoveRef<T &>
{
    using type = T;
};

template <typename T>
struct RemoveRef<T &&>
{
    using type = T;
};

template <typename T>
void my_swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
class my_less
{
public:
    bool operator()(const T &a, const T &b) const
    {
        return a < b;
    }
};

template <typename T>
class my_greater
{
public:
    bool operator()(const T &a, const T &b)
    {
        return a > b;
    }
};

#endif
