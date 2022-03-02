// 1197. 최소 스패닝 트리
// G4

#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<tuple<int, int, int>> cost;

int p[10010];

bool MySortFunc(tuple<int, int, int> a, tuple<int, int, int> b)
{
    return get<0>(a) < get<0>(b);
}


int MyFind(int x)
{
    if(p[x] == x)
        return x;

    return MyFind(p[x]);
}

void MyUnion(int x, int y)
{
    x = MyFind(x);
    y = MyFind(y);

    if(x < y)
        p[y] = x;
    else
        p[x] = y;
}


int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> V >> E;

    while(E--)
    {
        int A, B, C;
        cin >> A >> B >> C;

        cost.push_back({C, A, B});
    }

    sort(cost.begin(), cost.end(), MySortFunc);

    // union find
    for (int i = 1; i <= V; i++)
    {
        p[i] = i;
    }

    int count = 0;
    int ans = 0;

    for(auto a : cost)
    {
        if(count == V-1)
            break;

        int A = get<1>(a);
        int B = get<2>(a);

        if(MyFind(A) == MyFind(B))
            continue;

        ans += get<0>(a);
        MyUnion(A, B);
    }

    cout << ans;
}