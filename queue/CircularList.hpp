#pragma once

template <typename E>
struct CNode
{
    E data;
    CNode *next;
    CNode(E d = E{}, CNode<E> *nxt = nullptr)
    {
        data = d;
        next = nxt;
    }
};

template <typename E>
class CircularList
{
private:
    CNode<E> *cursor;

public:
    CircularList() : cursor(nullptr) {}

    ~CircularList()
    {
        while (!empty())
            remove();
    }

    bool empty() const
    {
        return (cursor == nullptr);
    }

    E &back()
    {
        return (cursor->data);
    }

    E &front()
    {
        return (cursor->next->data);
    }

    void advance()
    {
        cursor = cursor->next;
    }

    void add(const E &e)
    {
        CNode<E> *v = new CNode<E>(e);
        if (cursor)
        {
            v->next = cursor->next;
            cursor->next = v;
        }
        else
        {
            v->next = v;
            cursor = v;
        }
    }

    void remove()
    {
        CNode<E> *old = cursor->next;
        if (old == cursor)
            cursor = nullptr;
        else
            cursor->next = old->next;
        delete old;
    }
};
