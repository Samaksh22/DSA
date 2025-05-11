#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

template <typename T>
struct SNode
{
    T data;
    SNode *next;
    SNode(T d = NULL)
    {
        data = d;
    }
};

template <typename T>
class SLinkedList
{
private:
    SNode<T> *head;

public:
    SLinkedList();
    ~SLinkedList();
    const T &front() const;
    void addFront(const T &data);
    void removeFront();
};

#endif