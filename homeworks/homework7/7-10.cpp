#include <iostream>
using namespace std;

class Object
{
protected:
    double weight;

public:
    Object(double w = 0.0) : weight(w)
    {
        cout << "Object constructor called" << endl;
    }
    ~Object()
    {
        cout << "Object destructor called" << endl;
    }
    void setWeight(double w) { weight = w; }
    double getWeight() const { return weight; }
    void display() const
    {
        cout << "Object weight: " << weight << endl;
    }
};

class Box : public Object
{
private:
    double height, width;

public:
    Box(double w = 0.0, double h = 0.0, double wd = 0.0)
        : Object(w), height(h), width(wd)
    {
        cout << "Box constructor called" << endl;
    }
    ~Box()
    {
        cout << "Box destructor called" << endl;
    }
    void setDimensions(double h, double wd)
    {
        height = h;
        width = wd;
    }
    void display() const
    {
        Object::display();
        cout << "Box height: " << height << ", width: " << width << endl;
    }
};

int main()
{

    Box myBox(10.5, 5.0, 8.0);
    myBox.display();

    return 0;
}
