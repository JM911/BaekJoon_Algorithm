// 11286. 절댓값 힙
// S1

#include <bits/stdc++.h>
using namespace std;

int N;
int arr[200010];
int curIdx = 1;     // 다음 push에 넣을 칸의 인덱스

bool MyCompare(int a, int b)
{
    // 앞의 것이 절댓값이 더 작거나, 혹은 같은 절댓값 & 더 작은 값일때 true 반환 (= 앞의 것이 더 위로 가야하는지 반환)
    if(abs(a) == abs(b))
        return a < b;

    return abs(a) < abs(b);
}

void MyPush(int x)
{
    int tmpIdx = curIdx;
    
    
    while(MyCompare(x, arr[tmpIdx/2]))
    {
        arr[tmpIdx] = arr[tmpIdx / 2];
        tmpIdx /= 2;
    }

    arr[tmpIdx] = x;
    curIdx++;
}

int MyPop()
{
    if(curIdx == 1)
        return 0;

    curIdx--;
    int ret = arr[1];

    int tmpIdx = 1;
    int leftIdx = 2;
    int rightIdx = 3;

    while(MyCompare(arr[leftIdx], arr[curIdx]) || MyCompare(arr[rightIdx], arr[curIdx]))
    {
        if(leftIdx > curIdx-1)
            break;

        if(leftIdx == curIdx-1 || MyCompare(arr[leftIdx], arr[rightIdx]))
        {
            arr[tmpIdx] = arr[leftIdx];
            tmpIdx = leftIdx;
        }

        else
        {
            arr[tmpIdx] = arr[rightIdx];
            tmpIdx = rightIdx;
        }

        leftIdx = 2 * tmpIdx;
        rightIdx = leftIdx + 1;
    }

    arr[tmpIdx] = arr[curIdx];

    return ret;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;

    while(N--)
    {
        int tmp;
        cin >> tmp;

        if(tmp == 0)
        {
            cout << MyPop() << '\n';
        }
        else
        {
            MyPush(tmp);
        }
    }
}