#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 10
typedef int Elem;

class Deque
{
private:
    Elem *arr;
    int capacity;
    int n;
    int i;

public:
    Deque(int c) : capacity(c), n(0), i(0)
    {
        arr = new Elem[c];
    }

    ~Deque()
    {
        delete[] arr;
    }

    void printDeque()
    {
        cout << "Deque: ";

        int t = 0;
        while (t < capacity)
        {
            int j = (i + t) % capacity;
            if (t < n)
                cout << arr[j] << " ";
            else
                cout << "_ ";

            ++t;
        }

        cout << endl;
    }

    int size()
    {
        return n;
    }

    Elem front()
    {
        if (n == 0)
            return Elem{};
        return arr[i];
    }

    Elem back()
    {
        if (n == 0)
            return Elem{};
        int j = (i + n - 1) % capacity;
        return arr[j];
    }

    void addFront(Elem e)
    {
        if (n == capacity)
            cout << "Deque is Full ..." << endl;
        else
        {
            i = (i - 1) % capacity;
            ++n;
            arr[i] = e;
        }
    }

    void addBack(Elem e)
    {
        if (n == capacity)
            cout << "Deque is Full ..." << endl;
        else
        {
            int j = (i + n) % capacity;
            ++n;
            arr[j] = e;
        }
    }

    void removeFront()
    {
        if (n == 0)
            cout << "Deque is Empty ..." << endl;
        else
        {
            i = (i + 1) % capacity;
            --n;
        }
    }

    void removeBack()
    {
        if (n == 0)
            cout << "Deque is Empty ..." << endl;
        else
        {
            --n;
        }
    }
};

int main()
{
    Deque q(6);
    
    q.printDeque();
    
    q.addFront(1);
    q.addFront(2);
    
    q.printDeque();
    
    q.removeBack();
    
    q.printDeque();
    
    q.addBack(3);
    q.addFront(6);
    
    q.printDeque();

    q.addBack(7);
    q.addBack(8);
    q.addBack(9);
    
    q.printDeque();

    q.removeFront();

    q.printDeque();
    
    q.addBack(9);

    q.printDeque();

    return 0;
}