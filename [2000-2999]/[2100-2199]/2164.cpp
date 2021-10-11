// 2164. 카드2
// S4

#include <iostream>
using namespace std;

class Node
{
public:
    Node() : _data(0), _next(nullptr)
    {

    }

    Node(int n) : _data(n), _next(nullptr)
    {

    }

    ~Node()
    {

    }

public:
    int _data;
    Node* _next;
};

class List
{
public:
    List() : head(nullptr), tail(nullptr)
    {

    }

    ~List()
    {
        if (head)
            delete head;
    }

    void Insert(int data)
    {
        Node* newNode = new Node(data);

        if (head == nullptr)
            tail = newNode;

        newNode->_next = head;
        head = newNode;
    }

    bool IsOnlyOne()
    {
        if (head->_next == nullptr)
            return true;
        else
            return false;
    }

    void RemoveFirst()
    {
        if (head->_next)
        {
            Node* temp = head->_next;
            delete head;
            head = temp;
        }
    }

    void FirstToLast()
    {
        tail->_next = head;
        head = head->_next;
        tail->_next->_next = nullptr;
        tail = tail->_next;
    }

public:
    Node* head;
    Node* tail;
};

int main()
{
    List list;
    int N;
    cin >> N;

    if (N == 1)
    {
        cout << 1;
        return 0;
    }

    for (int i = (N / 2) * 2; i > 0; i -= 2)
    {
        list.Insert(i);
    }

    if (N % 2 == 0)
    {
        while (!list.IsOnlyOne())
        {
            list.RemoveFirst();
            list.FirstToLast();
        }
    }

    else
    {
        while (!list.IsOnlyOne())
        {
            list.FirstToLast();
            list.RemoveFirst();
        }
    }

    cout << list.head->_data;

    return 0;
}