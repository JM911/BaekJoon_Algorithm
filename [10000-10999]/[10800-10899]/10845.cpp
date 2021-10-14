// 10845. 큐
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

class MyQueue
{
public:
    MyQueue() : _rear(nullptr), _front(nullptr), _size(0)
    {

    }

    void Push(int data)
    {
        Node* newNode = new Node(data);
        newNode->_next = nullptr;
        if (_size == 0)
        {
            _front = newNode;
        }
        else
        {
            _rear->_next = newNode;
        }
        _rear = newNode;

        _size++;
    }

    int Pop()
    {
        if (_size == 0)
            return -1;
        
        Node* target = _front;
        int temp = target->_data;

        _front = target->_next;

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

    int Front()
    {
        if (_size == 0)
            return -1;

        return _front->_data;
    }

    int Back()
    {
        if (_size == 0)
            return -1;

        return _rear->_data;
    }

private:
    Node* _rear;
    Node* _front;
    int _size;
};

int main()
{
    MyQueue q;
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
                q.Push(n);
                break;
            case 'o':
                cout << q.Pop() << endl;
                break;
            }
            break;
        case 's':
            cout << q.Size() << endl;
            break;
        case 'e':
            cout << q.Empty() << endl;
            break;
        case 'f':
            cout << q.Front() << endl;
            break;
        case 'b':
            cout << q.Back() << endl;
            break;
        }
    }

    return 0;
}