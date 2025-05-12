#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

template <typename T>
struct SNode
{
    T data;
    SNode *next;
    SNode(T d = T());
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

template <typename E>
SNode<E>::SNode(E d)
{
    data = d;
    next = nullptr;
}

template <typename E>
SLinkedList<E>::SLinkedList()
{
    head = nullptr;
}

template <typename E>
SLinkedList<E>::~SLinkedList()
{
    while (!front())
        removeFront();
}

template <typename E>
const E &SLinkedList<E>::front() const
{
    return head->data;
}

template <typename E>
void SLinkedList<E>::addFront(const E &data)
{
    SNode<E> *newNode = new SNode<E>(data);
    newNode->next = head;
    head = newNode;
}

template <typename E>
void SLinkedList<E>::removeFront()
{
    SNode<E> *old = head;
    head = old->next;
    delete old;
}

#endif