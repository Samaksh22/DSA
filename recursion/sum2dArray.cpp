#include <iostream>
using namespace std;

int arr[3][3] = {{1, 1, 1},
                 {1, 1, 1},
                 {1, 1, 1}};

int rowSum(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;

    cout << i << " " << j << endl;
    return arr[i][j] + rowSum(i, j - 1);
}

int sum2d(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;

    return rowSum(i, j) + sum2d(i - 1, j);
}

int main()
{
    cout << sum2d(2, 2);
    return EXIT_SUCCESS;
}