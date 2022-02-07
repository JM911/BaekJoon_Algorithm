// 1715. 카드 정렬하기
// G4

#include <bits/stdc++.h>
using namespace std;

int N;
long long sum;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;

    while(N--)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    while(pq.size() > 1)
    {
        int A = pq.top();
        pq.pop();
        int B = pq.top();
        pq.pop();

        sum += A + B;
        pq.push(A + B);
    }

    cout << sum;
}