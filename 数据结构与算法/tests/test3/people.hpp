#ifndef PEOPLE_HPP
#define PEOPLE_HPP

#include "my_string.hpp"
#include <iostream>
class people
{
private:
    my_string name;  // 姓名
    my_string phone; // 电话号码
    int clss;        // 班级
    int dorm;        // 宿舍号

public:
    people() {}
    people(my_string name_, my_string phone_, int clss_, int dorm_) : name(name_), phone(phone_), clss(clss_), dorm(dorm_) {}
    people(people &&other) noexcept : name(std::move(other.name)), phone(std::move(other.phone)), clss(other.clss), dorm(other.dorm) {}
    people(const people &other) : name(other.name), phone(other.phone), clss(other.clss), dorm(other.dorm) {}

    ~people() {}

    people &operator=(people &&other) noexcept
    {
        name = std::move(other.name);
        phone = std::move(other.phone);
        clss = other.clss;
        dorm = other.dorm;
        return *this;
    }
    people &operator=(const people &other)
    {
        name = other.name;
        phone = other.phone;
        clss = other.clss;
        dorm = other.dorm;
        return *this;
    }

    // get方法(均为非const，便于修改)
    my_string &get_name()
    {
        return name;
    }
    my_string &get_phone()
    {
        return phone;
    }
    int &get_class()
    {
        return clss;
    }
    int &get_dorm()
    {
        return dorm;
    }

    // set方法
    void set_phone(const my_string &tar)
    {
        phone = tar;
    }
    void set_phone(my_string &&tar)
    {
        phone = std::move(tar);
    }

    void set_class(int new_clss)
    {
        clss = new_clss;
    }

    void set_dorm(int new_dorm)
    {
        dorm = new_dorm;
    }

    friend std::istream &operator>>(std::istream &is, people &tar);
};

std::istream &operator>>(std::istream &is, people &tar)
{
    is >> tar.name >> tar.phone >> tar.clss >> tar.dorm;
    return is;
}

#endif
