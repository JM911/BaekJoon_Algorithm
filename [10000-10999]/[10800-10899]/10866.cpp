// 10866. 덱
// S4

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    Node() : _data(0), _next(nullptr), _prev(nullptr)
    {

    }

    Node(int data) : _data(data), _next(nullptr), _prev(nullptr)
    {

    }

public:
    int _data;
    Node* _next;
    Node* _prev;
};

class MyDeque
{
public:
    MyDeque() : _size(0)
    {
        _head = new Node();
        _head->_next = _head;
        _head->_prev = _head;
    }

    ~MyDeque()
    {
        while (_size > 0)
            pop_back();

        if (_head)
            delete _head;
    }

    void push_front(int x)
    {
        Node* newNode = new Node(x);
        newNode->_next = _head->_next;
        newNode->_prev = _head;

        _head->_next->_prev = newNode;
        _head->_next = newNode;

        _size++;
    }

    void push_back(int x)
    {
        Node* newNode = new Node(x);
        newNode->_prev = _head->_prev;
        newNode->_next = _head;

        _head->_prev->_next = newNode;
        _head->_prev = newNode;

        _size++;
    }

    int pop_front()
    {
        if (_size == 0)
            return -1;

        Node* target = _head->_next;
        int temp = target->_data;

        _head->_next = target->_next;
        target->_next->_prev = _head;
        delete target;
        _size--;

        return temp;
    }

    int pop_back()
    {
        if (_size == 0)
            return -1;

        Node* target = _head->_prev;
        int temp = target->_data;

        _head->_prev = target->_prev;
        target->_prev->_next = _head;
        delete target;
        _size--;

        return temp;
    }

    int size() { return _size; }
    bool empty() { return _size == 0; }

    int front()
    {
        if (_size == 0)
            return -1;
        return _head->_next->_data;
    }

    int back()
    {
        if (_size == 0)
            return -1;
        return _head->_prev->_data;
    }

private:
    Node* _head;
    int _size;
};

int main()
{
    MyDeque md;
    int N;
    cin >> N;

    while (N-- > 0)
    {
        string str;
        cin >> str;
        
        if (str == "push_front")
        {
            int n;
            cin >> n;
            md.push_front(n);
        }

        if (str == "push_back")
        {
            int n;
            cin >> n;
            md.push_back(n);
        }

        if (str == "pop_front")
            cout << md.pop_front() << endl;

        if (str == "pop_back")
            cout << md.pop_back() << endl;

        if (str == "size")
            cout << md.size() << endl;

        if (str == "empty")
            cout << md.empty() << endl;

        if (str == "front")
            cout << md.front() << endl;

        if (str == "back")
            cout << md.back() << endl;
    }

    return 0;
}