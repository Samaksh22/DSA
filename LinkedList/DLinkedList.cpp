#include <iostream>
#include <string>
using namespace std;

template <typename Elem>
struct DNode
{
    Elem elem;
    DNode<Elem> *prev;
    DNode<Elem> *next;
};

template <typename Elem>
class DLinkedList
{
private:
    DNode<Elem> *head;
    DNode<Elem> *tail;

public:
    DLinkedList()
    {
        head = new DNode<Elem>;
        tail = new DNode<Elem>;
        head->next = tail;
        tail->next = head;
    }

    ~DLinkedList()
    {
        while (!empty())
            removeFront();
        delete head;
        delete tail;
    }

    bool empty() const
    {
        return (head->next == tail);
    }

    const Elem &front() const
    {
        return head->next->elem;
    }

    const Elem *back() const
    {
        return tail->prev->elem;
    }

    void add(DNode<Elem> *v, const Elem &e)
    {
        DNode<Elem> *u = new DNode;
        u->elem = e;
        u->next = v;
        u->prev = v->prev;
        v->prev->next = v->prev = u;
    }

    void addFront(const Elem &e)
    {
        add(head->next, e);
    }

    void addBack(const Elem &e)
    {
        add(tail, e);
    }

    void remove(DNode<Elem> *v)
    {
        DNode<Elem> *u = v->prev;
        DNode<Elem> *w = v->next;
        u->next = w;
        w->prev = u;
        delete v;
    }

    void removeFront()
    {
        remove(head->next);
    }

    void removeBack()
    {
        remove(tail->prev);
    }
};

template <typename E>
void listReverse(DLinkedList<E> &L)
{
    DLinkedList<E> T;
    while (!L.empty())
    {
        E s = L.front();
        L.removeFront();
        T.addFront(s);
    }

    while (!T.empty())
    {
        E s = T.front();
        T.removeFront();
        L.addBack(s);
    }
}