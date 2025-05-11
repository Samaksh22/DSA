#include <iostream>
using namespace std;

int recursiveFactorial(int n)
{
    if (n == 0)
        return 1;
    return n * recursiveFactorial(n - 1);
}

int main()
{
    int n = 5;
    cout << n <<" Factorial: " << recursiveFactorial(n) << endl;

    return 0;
}