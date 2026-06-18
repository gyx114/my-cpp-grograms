#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        throw 15.0;
    }
    catch (const float &e)
    {
        std::cout << "catched " << e << '\n';
    }
}
