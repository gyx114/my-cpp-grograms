#include <iostream>
#include "my_vector.hpp"
#include "my_string.hpp"
#include "people.hpp"
#include "contacts.hpp"

#define INSERT 0
#define DELETE 1
#define MODIFY 2
#define FIND 3
#define XOR_DORM 4

void one_operation(contacts &contact)
{
    int choice;
    std::cin >> choice;
    switch (choice)
    {
    case INSERT:
    {
        people p;
        std::cin >> p;
        contact.add_people(std::move(p));
        break;
    }

    case DELETE:
    {
        my_string name;
        std::cin >> name;
        contact.del_people(name);
        break;
    }

    case MODIFY:
    {
        my_string name;
        std::cin >> name;
        int op;
        std::cin >> op;
        contact.edit_people(op, name);
        break;
    }

    case FIND:
    {
        my_string name;
        std::cin >> name;
        std::cout << contact.find_people(name) << std::endl;
        break;
    }

    case XOR_DORM:
    {
        int clss;
        std::cin >> clss;
        std::cout << contact.XOR_dorm(clss) << std::endl;
        break;
    }

    default:
        std::cout << "操作不合法！" << std::endl;
        break;
    }
}

int main()
{
    int n;
    std::cin >> n;
    contacts contact;
    for (int i = 0; i < n; i++)
    {
        one_operation(contact);
    }
}
