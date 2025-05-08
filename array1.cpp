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
    // instead throws BUFFER OVERFLOW
    cout << f[m[2]] << endl << f[5] << endl;

    // pointers and arrays
    char c[] = {'c', 'a', 't'};
    char *p = c;
    char *q = &c[0];
    cout << c[2] << p[2] << q[2] << endl;
}