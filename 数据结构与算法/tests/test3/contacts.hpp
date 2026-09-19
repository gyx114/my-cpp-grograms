#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <iostream>
#include "my_vector.hpp"
#include "my_string.hpp"
#include "people.hpp"

#define EDIT_PHONE 1
#define EDIT_CLASS 2
#define EDIT_DORM 3

class contacts
{
private:
    my_vector<people> table;

public:
    contacts() {}
    ~contacts() {}

    void add_people(const people &p)
    {
        table.push_back(p);
    }
    void add_people(people &&p)
    {
        table.push_back(std::move(p));
    }

    void del_people(const my_string &name)
    {
        for (int i = 0; i < table.size(); i++)
        {
            if (table[i].get_name() == name)
            {
                table.erase(table.begin() + i);
                break;
            }
        }
    }

    void edit_people(char op, const my_string &name)
    {

        auto it = table.begin();
        for (; it != table.end() && it->get_name() != name; it++)
        {
        }
        if (it == table.end())
        {
            std::cout << "未找到对应联系人！" << std::endl;
            return;
        }
        switch (op)
        {
        case EDIT_PHONE:
            std::cin >> it->get_phone();
            break;

        case EDIT_CLASS:
            std::cin >> it->get_class();
            break;
        case EDIT_DORM:
            std::cin >> it->get_dorm();
            break;
        default:
            std::cout << "标号不合法!" << std::endl;
            break;
        }
    }

    bool find_people(const my_string &name)
    {
        auto it = table.begin();
        for (; it != table.end(); it++)
        {
            if (it->get_name() == name)
            {
                break;
            }
        }
        return it != table.end();
    }

    int XOR_dorm(int clss)
    {
        int ans = 0;
        for (auto it = table.begin(); it != table.end(); it++)
        {
            if (it->get_class() == clss)
            {
                ans ^= it->get_dorm();
            }
        }
        return ans;
    }
};

#endif
