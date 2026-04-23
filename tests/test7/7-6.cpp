#include <iostream>
using namespace std;

class MyArray
{
    int array_size;
    int *arr = NULL;

public:
    MyArray(int asize) : array_size(asize)
    {
        arr = new int[array_size];
        for (int i = 0; i < array_size; i++)
        {
            arr[i] = 0;
        }
    }
    ~MyArray()
    {
        delete[] arr;
    }

    // MyArray &operator=(const MyArray &arr2)
    // {
    //     if (this == &arr2)
    //     {
    //         return *this;
    //     }
    //     else
    //     {
    //         if (this->array_size != arr2.array_size)
    //         {
    //             cerr << "大小不一样！" << endl;
    //             return *this;
    //         }
    //         else
    //         {
    //             for (int i = 0; i < this->array_size; i++)
    //             {
    //                 (this->arr)[i] = arr2.arr[i];
    //             }
    //             return *this;
    //         }
    //     }
    // }

    int getArraySize() const
    {
        return array_size;
    }
    int getArr(int idx) const
    {
        if (idx >= array_size)
        {
            cout << "overflow" << endl;
            exit(-1);
        }
        return arr[idx];
    }
    void setArr(int idx, int v)
    {
        if (idx >= array_size)
        {
            cout << "overflow" << endl;
            exit(-1);
        }
        arr[idx] = v;
    }
    void print() const
    {
        cout << "addr: " << arr << " ";
        cout << "contents: " << " ";
        for (int i = 0; i < array_size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    MyArray arr1(10), arr2(10);
    for (int i = 0; i < 10; i++)
    {
        arr1.setArr(i, i);
        arr2.setArr(i, 2 * i);
    }
    arr1.print();
    arr2.print();
    arr1 = arr2;
    arr1.print();
}
