#include <iostream>
using namespace std;

int main()
{
    int x = 6;
    cout << x << endl;
    int &y = x;
    y = 10;
    cout << x << endl;
}