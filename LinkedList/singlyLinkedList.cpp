#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string val;
    Node *next;
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList()
    {
        while (!empty())
            removeFront();
    }

    bool empty() const
    {
        return (head == nullptr);
    }

    const string& front() const
    {
        return head->val;
    }

    void addFront(const string& e)
    {
        Node *v = new Node;
        v->val = e;
        v->next = head;
        head = v;
    }

    void removeFront()
    {
        Node *old = head;
        head = old->next;
        delete old;
    }
};

int main()
{
}