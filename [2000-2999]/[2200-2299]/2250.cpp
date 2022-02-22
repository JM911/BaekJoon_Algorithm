// 2250. 트리의 높이와 너비
// G2

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 10010

int N;
int x[MAX_NUM];
int y[MAX_NUM];
vector<int> htoi[MAX_NUM];

int p[MAX_NUM];
int lch[MAX_NUM];
int rch[MAX_NUM];

int curX = 1;
int ansHeight, ansWidth;

void MyInorder(int r)
{
    if(r == -1)
        return;

    MyInorder(lch[r]);
    x[r] = curX++;
    MyInorder(rch[r]);
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int tmpP, tmpL, tmpR;
        cin >> tmpP >> tmpL >> tmpR;

        if(tmpL != -1)
            p[tmpL] = tmpP;
        if(tmpR != -1)
            p[tmpR] = tmpP;

        lch[tmpP] = tmpL;
        rch[tmpP] = tmpR;
    }

    // 루트 탐색
    int root = 1;
    while(p[root] != 0)
    {
        root = p[root];
    }

    // 높이 배정
    y[root] = 1;
    htoi[root].push_back(1);

    queue<int> q;
    q.push(root);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        int curLeft = lch[cur];
        int curRight = rch[cur];

        if(curLeft > 0)
        {
            y[curLeft] = y[cur] + 1;
            htoi[y[curLeft]].push_back(curLeft);
            q.push(curLeft);
        }

        if(curRight > 0)
        {
            y[curRight] = y[cur] + 1;
            htoi[y[curRight]].push_back(curRight);
            q.push(curRight);
        }
    }

    // x 배정
    MyInorder(root);

    for (int i = 1; i <= MAX_NUM - 5; i++)
    {
        vector<int> curHeightX;

        for(auto t : htoi[i])
        {
            curHeightX.push_back(x[t]);
        }

        if(curHeightX.size() == 0)
            continue;

        int RR = *max_element(curHeightX.begin(), curHeightX.end());
        int LL = *min_element(curHeightX.begin(), curHeightX.end());
        int curWidth = RR - LL + 1;

        if(ansWidth < curWidth)
        {
            ansHeight = i;
            ansWidth = curWidth;
        }
    }

    cout << ansHeight << ' ' << ansWidth;
}