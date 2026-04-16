#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
protected:
    const float speed;
    float location = 0;

public:
    Vehicle(float spd) : speed(spd), location(0)
    {
        cout << "vehicle constructor" << endl;
    }
    ~Vehicle()
    {
        cout << "vehicle destructor" << endl;
    }
    void drive(float duration)
    {
        float former = location;
        location += duration * speed;
        cout << "from " << former << " to " << location << endl;
        cout << &location << endl;
    }
};

class Truck : virtual public Vehicle
{
protected:
    const float load_capacity;
    float load_weight = 0;

public:
    Truck(float spd, float ldcapa) : Vehicle(spd), load_capacity(ldcapa), load_weight(0) { cout << "truck constructor" << endl; }
    ~Truck()
    {
        cout << "truck destructor" << endl;
    }

    bool load(float w)
    {
        if (load_weight + w <= load_capacity)
        {
            load_weight += w;
            return true;
        }
        else
        {
            cout << "overload!" << endl;
            return false;
        }
    }
    bool unload(float w)
    {
        if (load_weight - w >= 0)
        {
            load_weight -= w;
            return true;
        }
        else
        {
            cout << "unload too much!" << endl;
            return false;
        }
    }
};

class RefrigeratorCar : virtual public Vehicle
{
protected:
    float temperature;
    const float room_temperature;

public:
    RefrigeratorCar(float spd, float rmtemp) : Vehicle(spd), room_temperature(rmtemp), temperature(rmtemp) { cout << "refrigeratorcar constructor" << endl; }
    ~RefrigeratorCar()
    {
        cout << "RefrigeratorCar destructor" << endl;
    }
    void reset()
    {
        temperature = room_temperature;
    }
};

class RefrigeratorTruck : public Truck, public RefrigeratorCar
{
public:
    // RefrigeratorTruck(float spd, float ldcapa, float rmtemp) : Truck(spd, ldcapa), RefrigeratorCar(spd, rmtemp) { cout << "RefrigeratorTruck constructor" << endl; }

    RefrigeratorTruck(float s, float l, float f) : Vehicle(s), Truck(l, s + 1), RefrigeratorCar(f, s + 2)
    {
        cout << "RefrigeratorTruck is constructed" << endl;
    }
    ~RefrigeratorTruck()
    {
        cout << "RefrigeratorTruck destructor" << endl;
    }
    bool load(float w, float t)
    {
        if (!Truck::load(w))
        {
            return false;
        }
        else
        {
            if (t < temperature)
            {
                temperature = t;
            }
            return true;
        }
    }

    bool unload(float w)
    {
        if (!Truck::unload(w))
        {
            return false;
        }
        else
        {
            if (load_weight == 0)
            {
                reset();
            }
            return true;
        }
    }
};

int main()
{
    // speed = 10, load_capacity = 1000, roomTemperature = 28
    RefrigeratorTruck t(10, 1000, 28);
    t.RefrigeratorCar::drive(1);
    t.Truck::drive(1);
    // t.drive(1);
}
