#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert_sort(int arr[], int n)
{
    cout << "original state:" << endl;
    print(arr, n);
    for (int i = 1; i < n; i++)
    {
        int tmp = i - 1;
        auto val = arr[i];
        while (tmp >= 0 && arr[tmp] > val)
        {
            arr[tmp + 1] = arr[tmp];
            tmp--;
        }
        arr[tmp + 1] = val;

        cout << "第" << i << "步:" << endl;
        print(arr, n);
    }
}

int main()
{
    int data1[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int len = sizeof(data1) / sizeof(int);
    insert_sort(data1, len);
}
