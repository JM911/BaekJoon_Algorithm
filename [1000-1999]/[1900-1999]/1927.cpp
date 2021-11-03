// 1927. 최소 힙
// S1

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int lHeap[100001];
int numOfHeap;

int GetParentIdx(int idx)
{
    return idx / 2;
}

int GetLChildIdx(int idx)
{
    return idx * 2;
}

int GetRChildIdx(int idx)
{
    return GetLChildIdx(idx) + 1;
}

int GetSmallerChildIdx(int idx)
{
    if(GetLChildIdx(idx) > numOfHeap)
        return 0;
    if(GetRChildIdx(idx) > numOfHeap)
        return GetLChildIdx(idx);

    int left = GetLChildIdx(idx);
    int right = GetRChildIdx(idx);

    if(lHeap[left] < lHeap[right])
        return left;
    else
        return right;
}

void HInsert(int val)
{
    int idx = ++numOfHeap;
    int pidx;

    while(idx != 1)
    {
        pidx = GetParentIdx(idx);

        if(val < lHeap[pidx])
        {
            lHeap[idx] = lHeap[pidx];
            idx = pidx;
        }

        else
            break;
    }

    lHeap[idx] = val;
}

int HDelete()
{
    int ret = lHeap[1];
    int val = lHeap[numOfHeap];
    int idx = 1;
    int cidx;

    while(cidx = GetSmallerChildIdx(idx))
    {
        if(val > lHeap[cidx])
        {
            lHeap[idx] = lHeap[cidx];
            idx = cidx;
        }

        else
            break;
    }

    lHeap[idx] = val;

    numOfHeap--;
    return ret;
}

int main()
{
    fastio;
    int N;
    cin >> N;

    int temp;

    while(N--)
    {
        cin >> temp;

        if(temp==0)
        {
            if(numOfHeap == 0)
                cout << 0 << '\n';
            else
            {
                cout << HDelete() << '\n';
            }
        }

        else
            HInsert(temp);
    }

    return 0;
}
