#pragma once

// #include <string>
#include <iostream>
using namespace std;

typedef int Elem;

struct Node
{
    Elem elem;
    Node *prev;
    Node *next;

    Node(const Elem &e = Elem(), Node *p = nullptr, Node *n = nullptr)
    {
        elem = e;
        prev = p;
        next = n;
    }
};

class Iterator
{
private:
    Node *v;
    Iterator(Node *u)
    {
        v = u;
    }

    friend class NodeList;

public:
    Elem &operator*()
    {
        return v->elem;
    }

    bool operator==(const Iterator &p) const
    {
        return v == p.v;
    }

    bool operator!=(const Iterator &p) const
    {
        return v != p.v;
    }

    Iterator &operator++()
    {
        v = v->next;
        return *this;
    }

    Iterator &operator--()
    {
        v = v->prev;
        return *this;
    }
};

class NodeList
{
private:
    int n;
    Node *header;
    Node *trailer;

    void add(Node *v, const Elem &e)
    {
        Node *u = new Node(e);
        u->next = v;
        u->prev = v->prev;
        v->prev->next = u;
        v->prev = u;
        n++;
    }

    Elem remove(Node *v)
    {
        Node *u = v->prev;
        Node *w = v->next;
        u->next = w;
        w->prev = u;
        Elem e = v->elem;
        delete v;
        n--;
        return e;
    }

public:
    NodeList()
    {
        n = 0;
        header = new Node;
        trailer = new Node;
        header->next = trailer;
        trailer->prev = header;
    }

    ~NodeList()
    {
        while (header != nullptr)
        {
            Node *current = header;
            header = header->next;
            delete current;
        }
    }

    int size() const
    {
        return n;
    }

    bool empty() const
    {
        return size() == 0;
    }

    Iterator begin() const
    {
        return Iterator(header->next);
    }

    Iterator end() const
    {
        return Iterator(trailer);
    }

    void insertFront(const Elem &e)
    {
        add(header->next, e);
    }

    void insertBack(const Elem &e)
    {
        add(trailer, e);
    }

    void insert(const Iterator &p, const Elem &e)
    {
        add(p.v, e);
    }

    void eraseFront()
    {
        remove(header->next);
    }

    void eraseBack()
    {
        remove(trailer->prev);
    }

    void erase(const Iterator &p)
    {
        remove(p.v);
    }

    void printList() const
    {
        cout << "List (" << size() << " elements): ";
        if (empty()) {
            cout << "Empty." << endl;
            return;
        }
        for (Iterator it = begin(); it != end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
};