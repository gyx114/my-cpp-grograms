#include <iostream>
using namespace std;

template <class T>
void mySwap(T &x, T &y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <class T>
void bubbleSort(T a[], int n)
{
    int i = n - 1;
    while (i > 0)
    {
        int lastExchangeIndex = 0;
        for (int j = 0; j < i; j++)
            if (a[j + 1] < a[j])
            {
                mySwap(a[j], a[j + 1]);
                lastExchangeIndex = j;
            }
        i = lastExchangeIndex;
    }
}

template <class T>
void bubbleSort(T *a[], int n)
{
    int i = n - 1;
    while (i > 0)
    {
        int lastExchangeIndex = 0;
        for (int j = 0; j < i; j++)
            if (a[j + 1][0] < a[j][0])
            {
                mySwap(a[j], a[j + 1]);
                lastExchangeIndex = j;
            }
        i = lastExchangeIndex;
    }
}

int main()
{
    int D[10] = {2, 7, 3, 5, 10, 6, 9, 1, 4, 8};
    int *Dptr[10];
    for (int i = 0; i < 10; i++)
    {
        Dptr[i] = &D[i];
    }
    cout << "排序前结果： " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << *Dptr[i] << " ";
    }
    cout << endl;

    bubbleSort(Dptr, 10);

    cout << "排序后结果： " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << *Dptr[i] << " ";
    }
    cout << endl;
}
