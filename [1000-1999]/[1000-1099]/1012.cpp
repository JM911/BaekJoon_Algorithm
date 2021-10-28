// 1012. 유기농 배추
// S2

#include <iostream>
using namespace std;

typedef struct _node
{
    bool isCabbage = false;
    bool isChecked = false;
} Node;

Node ground[50][50];

bool Checking(int x, int y, int m, int n)
{
    bool first = false;

    if(ground[y][x].isCabbage == false || ground[y][x].isChecked == true)
        return false;
    else
    {
        ground[y][x].isChecked = true;
        first = true;
    }

    if(x-1>=0)
        Checking(x-1, y, m, n);
    if(y-1>=0)
        Checking(x, y-1, m, n);
    if(x+1<=m)
        Checking(x+1, y, m, n);
    if(y+1<=n)
        Checking(x, y+1, m, n);

    return first;
}

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        int M, N, K;
        scanf("%d %d %d", &M, &N, &K);

        int x, y;
        for(int i=0; i<K; i++)
        {
            scanf("%d %d", &x, &y);
            ground[y][x].isCabbage = true;
        }

        int sum = 0;

        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(Checking(i, j, M, N))
                    sum += 1;
            }
        }

        cout<<sum<<'\n';

        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                ground[j][i].isCabbage = false;
                ground[j][i].isChecked = false;
            }
        }
    }

}
