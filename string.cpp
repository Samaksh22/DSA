#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    string s = "Hello";
    string t = "world";
    string u = s + " " + t;
    
    cout << u << " " << u.size() << endl;
    
    // printf("%s\n", u.c_str());
    
    return 0;
}