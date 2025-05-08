#include <iostream>
using namespace std;

int main()
{
    double f[5];
    int m[10];

    // illegal access
    cout << f[5] << endl;
    f[5] = 2.5;
    m[2] = 4;

    // DOES NOT PRODUCE OUT OF BOUND
    // INSTEAD LEADS TO BUFFER OVERFLOW
    cout << f[m[2]] << endl << f[5];
}