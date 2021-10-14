// 10828. 스택
// S4

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    Node() : _data(0), _next(nullptr)
    {

    }

    Node(int data) : _data(data), _next(nullptr)
    {

    }

public:
    int _data;
    Node* _next;
};

class MyStack
{
public:
    MyStack() : _size(0)
    {
        _head = new Node();
        _head->_next = nullptr;
    }

    ~MyStack()
    {
        if (_head) delete _head;
    }

    void Push(int data)
    {
        Node* newNode = new Node(data);
        newNode->_next = _head->_next;
        _head->_next = newNode;
        _size++;
    }

    int Pop()
    {
        if (_head->_next == nullptr)
            return -1;

        Node* target = _head->_next;
        int temp = target->_data;
        _head->_next = target->_next;
        delete target;
        _size--;

        return temp;
    }

    int Size()
    {
        return _size;
    }

    int Empty()
    {
        if (_size == 0)
            return 1;
        else
            return 0;
    }

    int top()
    {
        if (_size == 0)
            return -1;
        else
            return _head->_next->_data;
    }

private:
    Node* _head;
    int _size;
};

int main()
{
    MyStack s;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;

        switch (str[0])
        {
        case 'p':
            switch (str[1])
            {
            case 'u':
                int n;
                cin >> n;
                s.Push(n);
                break;
            case 'o':
                cout << s.Pop() << endl;
                break;
            }
            break;
        case 's':
            cout << s.Size() << endl;
            break;
        case 'e':
            cout << s.Empty() << endl;
            break;
        case 't':
            cout << s.top() << endl;
            break;
        }
    }

    return 0;
}