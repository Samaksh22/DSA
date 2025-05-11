#include <iostream>
using namespace std;

void hanoi(int n, char from, char to, char via)
{
    if (n == 1)
    {
        cout << "Disk-1: From " << from << " To " << to << endl;
    }
    else
    {
        hanoi(n-1, from, via, to);
        cout << "Disk-" << n << ": From " << from << " To " << to << endl;
        hanoi(n-1, via, to, from);
    }
}

int main()
{
    hanoi(2, 'A', 'B', 'C');      
}