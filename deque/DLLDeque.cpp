#include "../LinkedList/DLinkedList.hpp"
#include <iostream>
#include <string>

using namespace std;
typedef int Elem;

class LinkedDeque
{
private:
    DLinkedList<Elem> D;
    int n;

public:
    LinkedDeque() : D() {}
    int size() const
    {
        return n;
    }

    bool empty() const
    {
        return n == 0;
    }

    const Elem &front() const
    {
        return D.front();
    }

    const Elem &back() const
    {
        return D.back();
    }

    void insertFront(const Elem &e)
    {
        D.addFront(e);
        n++;
    }

    void insertBack(const Elem &e)
    {
        D.addBack(e);
        n++;
    }

    void removeFront()
    {
        D.removeFront();
        n--;
    }

    void removeBack()
    {
        D.removeBack();
        n--;
    }
};


int main()
{
    LinkedDeque D;
    D.insertFront(1);
    cout << D.back() << endl;
    D.insertFront(2);
    cout << D.back() << endl;
    D.insertFront(3);
    cout << D.back() << endl;
    D.insertFront(4);
    cout << D.back() << endl;
    cout << endl;

    cout << D.back() << endl;
    D.removeBack();
    cout << D.back() << endl;
    D.removeBack();
    cout << D.back() << endl;
    D.removeBack();
    cout << D.back() << endl;
    D.removeBack();
}