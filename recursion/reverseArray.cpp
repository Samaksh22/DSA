#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    cout << "Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void recursiveReverse(int arr[], int i, int j)
{
    if (i < j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        recursiveReverse(arr, i + 1, j - 1);
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 6};
    int n = sizeof(arr) / sizeof(int);
    printArray(arr, n);
    recursiveReverse(arr, 0, n-1);
    printArray(arr, n);
}