#include <iostream>
#include <stdexcept>
using namespace std;

void fun(int opt)
{
    switch (opt)
    {
    case 1:
        throw exception();
        break;
    case 2:
        throw logic_error("logic err");
        break;
    case 3:
        throw out_of_range("out of range");
        break;
    default:
        break;
    }
}

int main()
{
    int op;
    do
    {
        cin >> op;
        try
        {
            fun(op);
        }

        catch (const out_of_range &e)
        {
            cerr << "caught by out_of_range" << '\n';
        }
        catch (const logic_error &e)
        {
            cerr << "caught by logic_error" << '\n';
        }
        catch (const std::exception &e)
        {
            std::cerr << "caught by exception" << '\n';
        }

    } while (op != -1);
}
