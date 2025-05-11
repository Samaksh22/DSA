#include <iostream>
using namespace std;

int binaryFib(int k)
{
    if (k <= 1)
        return k;

    return binaryFib(k - 1) + binaryFib(k - 2);
}

int main()
{
    cout << binaryFib(10);
}