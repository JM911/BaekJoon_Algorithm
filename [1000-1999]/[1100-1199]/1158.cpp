// 1158. 요세푸스 문제
// S5

#include <iostream>
using namespace std;

typedef struct ListNode
{
    int data;
    struct ListNode* next;
} ListNode;

void InsertAtEnd(ListNode** head, int data)
{
    ListNode* inserted = new ListNode;
    inserted->data = data;

    if (*head == nullptr)
    {
        *head = inserted;
        inserted->next = *head;
    }
    else
    {
        ListNode* tail = *head;
        while (tail->next != *head)
        {
            tail = tail->next;
        }
        tail->next = inserted;
        inserted->next = *head;
    }
}


int main()
{
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    int N, K;
    cin >> N >> K;
    
    for (int i = 0; i < N; i++)
    {
        InsertAtEnd(&head, i + 1);
    }

    ListNode* cur = head;

    if (N == 1)
    {
        cout << "<";
        cout << head->data;
        cout << ">";
    }

    else if (K == 1)
    {
        cout << "<";
        for (int i = 0; i < N-1; i++)
        {
            cout << cur->data<<", ";
            cur = cur->next;
        }
        cout << cur->data;
        cout << ">";
    }

    else
    {
        cout << "<";
        while (true)
        {
            for (int i = 0; i < K - 2; i++)
            {
                cur = cur->next;
            }

            if (cur->next == cur)
            {
                cout << cur->data;
                break;
            }
            else
            {
                cout << cur->next->data << ", ";
                cur->next = cur->next->next;
                cur = cur->next;
            }
        }
        cout << ">";
    }


    return 0;
}