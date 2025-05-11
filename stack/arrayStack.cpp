#include <iostream>
#include <stdexcept>
using namespace std;

#define MAX_CAPACITY 100

template <typename E>
class ArrayStack
{
private:
    E *S;
    int capacity;
    int t;

public:
    ArrayStack(int cap = MAX_CAPACITY)
    {
        S = new E[cap];
        int capacity = cap;
        int t = -1;
    }

    int size() const
    {
        return (t + 1);
    }

    bool empty() const
    {
        return (t < 0);
    }

    const E &top() const
    {
        if (empty())
            throw runtime_error("Stack is Empty!");
        return S[t];
    }

    void push(const E &e)
    {
        if (size() == capacity)
            throw runtime_error("Stack is Full!");
        S[++t] = e;
    }

    void pop()
    {
        if (empty())
            throw runtime_error("Stack is Empty!");
        --t;
    }
};

int main()
{
    ArrayStack<int> A; // A=[], size=0
    A.push(7);             // A=[7*], size=1
    A.push(13);            // A=[7, 13*], size=2
    cout << A.top() << endl;
    A.pop();                 // A=[7*], outputs: 13
    A.push(9);               // A=[7, 9*], size=2
    cout << A.top() << endl; // A=[7, 9*], outputs: 9
    cout << A.top() << endl;
    A.pop();                  // A=[7*], outputs: 9
    ArrayStack<string> B(10); // B=[], size=0
    B.push("Bob");            // B=[Bob*], size=1
    B.push("Alice");          // B=[Bob,Alice*], size=2
    cout << B.top() << endl;
    B.pop();       // B=[Bob*], outputs:Alice
    B.push("Eve"); // B=[Bob,Eve*], size=2
}