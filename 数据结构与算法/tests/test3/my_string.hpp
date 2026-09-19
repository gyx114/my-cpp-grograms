#ifndef MY_STRING
#define MY_STRING

#include <stdexcept>
#include <iostream>

inline int my_strlen(const char *str_)
{
    if (str_ == nullptr)
    {
        return 0;
    }
    int len = 0;
    for (int i = 0; str_[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}
inline void my_strcpy(char *dest, const char *src)
{
    if (!src || !dest)
    {
        throw std::logic_error("传入了空源或目的!");
    }
    else
    {
        int i = 0;
        for (; src[i] != '\0'; i++)
        {
            dest[i] = src[i];
        }
        dest[i] = '\0';
    }
}
inline int my_strcmp(const char *l, const char *r)
{
    if (l == nullptr || r == nullptr)
    {
        return -1;
    }
    while ((*l) && (*l == *r))
    {
        l++;
        r++;
    }
    return *(const unsigned char *)l - *(const unsigned char *)r;
}

class my_string
{
private:
    int len_;
    char *str_;

public:
    my_string(const char *str = nullptr)
    {
        if (str)
        {
            len_ = my_strlen(str);
            str_ = new char[len_ + 1];
            my_strcpy(str_, str);
        }
        else
        {
            len_ = 0;
            str_ = new char[1];
            str_[0] = '\0';
        }
    }
    my_string(const my_string &src)
    {
        len_ = src.len_;
        str_ = new char[len_ + 1];
        my_strcpy(str_, src.str_);
    }
    my_string(my_string &&other) noexcept : len_(other.len_), str_(other.str_)
    {
        // 对源对象置空
        other.len_ = 0;
        other.str_ = nullptr;
    }
    ~my_string()
    {
        delete[] str_;
    }

    my_string &operator=(const my_string &other)
    {
        if (this != &other)
        {
            delete[] str_;
            len_ = other.len_;
            str_ = new char[len_ + 1];
            my_strcpy(str_, other.str_);
        }
        return *this;
    }
    my_string &operator=(my_string &&other) noexcept
    {
        if (this != &other)
        {
            delete[] str_;
            str_ = other.str_;
            len_ = other.len_;
            other.len_ = 0;
            other.str_ = nullptr;
        }
        return *this;
    }
    my_string &operator=(const char *src)
    {
        delete[] str_;
        if (src)
        {
            len_ = my_strlen(src);
            str_ = new char[len_ + 1];
            my_strcpy(str_, src);
        }
        else
        {
            len_ = 0;
            str_ = new char[1];
            str_[0] = '\0';
        }
        return *this;
    }

    int length() const
    {
        return len_;
    }

    const char *c_str() const noexcept
    {
        return str_;
    }

    char &operator[](int idx)
    {
        if (idx < 0 || idx >= len_)
        {
            throw std::logic_error("下标越界！");
        }
        else
        {
            return str_[idx];
        }
    }
    const char &operator[](int idx) const
    {
        if (idx < 0 || idx >= len_)
        {
            throw std::logic_error("下标越界！");
        }
        else
        {
            return str_[idx];
        }
    }

    bool operator==(const my_string &r) const
    {
        return !my_strcmp(str_, r.str_);
    }

    bool operator!=(const my_string &r) const
    {
        return !operator==(r);
    }

    friend std::istream &operator>>(std::istream &is, my_string &tar);
    friend bool operator==(const char *l, const my_string &r);
    friend bool operator==(const my_string &l, const char *r);
};

std::istream &operator>>(std::istream &is, my_string &tar)
{
    char tmp[1024];
    is >> tmp;
    tar = tmp;
    return is;
}

inline bool operator==(const char *l, const my_string &r)
{
    return !my_strcmp(l, r.str_);
}
inline bool operator==(const my_string &l, const char *r)
{
    return !my_strcmp(l.str_, r);
}

inline bool operator!=(const char *l, const my_string &r)
{
    return !operator==(l, r);
}
inline bool operator!=(const my_string &l, const char *r)
{
    return !operator==(l, r);
}

#endif
