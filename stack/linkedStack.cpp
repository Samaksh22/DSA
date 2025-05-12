#include <iostream>
#include <stdexcept>
#include <string>
#include "sLinkedList.hpp"
using namespace std;

typedef int Elem;
class LinkedStack
{
private:
    SLinkedList<Elem> S;
    int n;
public:
    LinkedStack()
    {
        n = 0;
    }

    int size() const
    {
        return n;
    }

    bool empty() const
    {
        return (n == 0);
    }

    const Elem& top() const
    {
        if (empty())
            throw runtime_error("Top of empty stack!");
        return S.front();
    }

    void push(const Elem& e)
    {
        ++n;
        S.addFront(e);
    }

    void pop()
    {
        if (empty())
            throw runtime_error("Pop from empty stack!");
        S.removeFront();
    }
};

int main()
{
    LinkedStack S;
    S.push(5);
    S.push(10);
    
    cout << S.top() << endl;
    cout << ((S.empty()) ? "No Space" : "Yes") << endl; 
    
    S.pop();
    cout << S.top() << endl;
}