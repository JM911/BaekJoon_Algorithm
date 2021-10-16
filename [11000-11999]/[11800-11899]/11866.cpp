// 11866. 요세푸스 문제0
// S4

#include <iostream>
using namespace std;

class Node
{
public:
    Node() : _data(0), _next(nullptr), _prev(nullptr)
    {

    }

    Node(int value) : _data(value), _next(nullptr), _prev(nullptr)
    {

    }

public:
    int _data;
    Node* _next;
    Node* _prev;
};

class CList
{
public:
    CList() : _tail(nullptr), _cur(nullptr), _size(0)
    {

    }

    ~CList()
    {
        while (_size > 0)
            pop();
    }

    void push(int value)
    {
        Node* newNode = new Node(value);
        if (_size == 0)
        {
            newNode->_next = newNode;
            newNode->_prev = newNode;

        }
        else
        {
            newNode->_next = _tail->_next;
            newNode->_prev = _tail;
            _tail->_next->_prev = newNode;
            _tail->_next = newNode;
        }
        _tail = newNode;
        _size++;
    }

    int pop()
    {
        int temp = _cur->_data;
        Node* prevNode = _cur->_prev;
        prevNode->_next = _cur->_next;
        _cur->_next->_prev = prevNode;

        delete _cur;
        _cur = prevNode;
        _size--;

        return temp;
    }

    void init()
    {
        _cur = _tail;
    }

    void next()
    {
        _cur = _cur->_next;
    }

private:
    Node* _tail;
    Node* _cur;
    int _size;
};

int main()
{
    int N, K;
    cin >> N >> K;
    CList cl;

    for (int i = 1; i <= N; i++)
        cl.push(i);

    cl.init();

    cout << '<';
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < K; j++)
            cl.next();
        cout << cl.pop() << ", ";
    }
    cout << cl.pop() << '>';

    return 0;
}
