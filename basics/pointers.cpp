#include <iostream>

using namespace std;

int main()
{
    // a pointer holds the address of some variable
    // '&' <= this represents the address-of opreator
    // '*' <= this is used for derefrencing
    char ch = 'A';
    
    char *p = &ch;
    cout << (p == &ch) << " " << &ch << endl;

    cout << *p << endl;
    
    ch = 'Z';
    cout << *p << endl;
    
    *p = 'X';
    cout << ch;
}