#include <iostream>
using namespace std;

template <typename E>
class SNode
{
public:
    E elem;
    SNode<E> *next;
};

template <typename E>
class SLinkedList
{
private:
    SNode<E> *head;

public:
    SLinkedList() : head(nullptr) {}

    ~SLinkedList()
    {
        while (!empty())
            removeFront();
    }

    bool empty() const
    {
        return head == nullptr;
    }

    const E &front() const
    {
        return head->elem;
    }

    void addFront(const E &e)
    {
        SNode<E> *v = new SNode<E>;
        v->elem = e;
        v->next = head;
        head = v;
    }

    void removeFront()
    {
        SNode<E> *old = head;
        head = old->next;
        delete old;
    }
};

int main()
{
    SLinkedList<int> a;
    a.addFront(13);
    a.addFront(15);

    cout << a.front();
}