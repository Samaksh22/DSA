#include <iostream>

using namespace std;

int main()
{
    
    return 0;
}

void insertionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        int j = i - 1;
        while ((j >= 0) && (arr[j] > curr))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = curr;
    }
}