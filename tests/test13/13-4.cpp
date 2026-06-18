#include <memory>

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
