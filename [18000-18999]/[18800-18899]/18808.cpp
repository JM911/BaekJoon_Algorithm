// 18808. 스티커 붙이기
// G3

#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool notebook[50][50];
bool sticker[50][50];
bool newSticker[50][50];

void Stick(int startX, int startY, int h, int w)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (notebook[startX + i][startY + j] == 0 && sticker[i][j] == 1)
                notebook[startX + i][startY + j] = 1;
        }
    }
}

bool CanStick(int startX, int startY, int h, int w)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if(notebook[startX + i][startY + j] == 1 && sticker[i][j] == 1)
                return false;
        }
    }
    return true;
}

void RotateStickerOnce(int& h, int& w)
{
    int temp = h;
    h = w;
    w = temp;

    //fill(&newSticker[0][0], &newSticker[49][50], false);        // 디버깅용

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            newSticker[i][j] = sticker[w - j - 1][i];
        }
    }        
    
    for (int i = 0; i < h; i++) 
    {
        for (int j = 0; j < w; j++)
        {
            sticker[i][j] = newSticker[i][j];
        }
    }
}

int main()
{
    fastio;
    int N, M, K;
    cin >> N >> M >> K;

    while(K--)
    {
        int sHeight, sWidth;
        cin >> sHeight >> sWidth;

        for (int i = 0; i < sHeight; i++)
        {
            for (int j = 0; j < sWidth; j++)
            {
                cin >> sticker[i][j];
            }
        }

        for (int rot = 0; rot < 4; rot++)
        {
            bool isSticked = false;
            for (int i = 0; i < N - sHeight + 1; i++)
            {
                for (int j = 0; j < M - sWidth + 1; j++)
                {
                    if(CanStick(i, j, sHeight, sWidth))
                    {
                        isSticked = true;
                        Stick(i, j, sHeight, sWidth);
                        break;
                    }
                }

                if(isSticked)
                    break;
            }

            if(isSticked)
                break;

            RotateStickerOnce(sHeight, sWidth);
        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(notebook[i][j] == 1)
                ans++;
        }
    }

    cout << ans;
}