#include <iostream>
#include <string>
using namespace std;

typedef string Elem;

struct CNode
{
    Elem elem;
    CNode *next;
};

class CircleList
{
private:
    CNode *cursor;

public:
    CircleList() : cursor(nullptr) {}

    ~CircleList()
    {
        while (!empty())
            remove();
    }

    bool empty() const
    {
        return cursor == nullptr;
    }

    const Elem &back()
    {
        return cursor->elem;
    }

    const Elem &front()
    {
        return cursor->next->elem;
    }

    void advance()
    {
        cursor = cursor->next;
    }

    void add(const Elem &e)
    {
        CNode *v = new CNode;
        v->elem = e;
        if (cursor == nullptr)
        {
            v->next = v;
            cursor = v;
        }
        else
        {
            v->next = cursor->next;
            cursor->next = v;
        }
    }

    void remove()
    {
        CNode *old = cursor->next;
        if (old == cursor)
            cursor = nullptr;
        else
            cursor->next = old->next;
        delete old;
    }
};

int main()
{
    CircleList playList;
    playList.add("Piya Tose");
    playList.add("Abhi Na Jao Chhod Kar");
    playList.add("Aaj Jaane Ki Zid");

    playList.advance();
    playList.advance();
    
    playList.remove();

    playList.add("Ajeeb Dastan");
    cout << playList.front() << endl;
    return EXIT_SUCCESS;
}