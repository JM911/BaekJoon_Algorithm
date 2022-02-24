// 21276. 계보 복원가 호석
// G3

#include <bits/stdc++.h>
using namespace std;

#define MAX_NUM 1010

int N, M;
vector<string> townMemVec;                  // 인덱스 -> 이름
unordered_map<string, int> townMemMap;      // 이름 -> 인덱스

int ind[MAX_NUM];                   // 인덱스에 대한 indegree
vector<string> adj[MAX_NUM];        // 조상
set<string> ansChild[MAX_NUM];      // 자식
set<string> ansRoot;                // 루트

queue<int> q;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string tmpName;
        cin >> tmpName;

        townMemVec.push_back(tmpName);
        //townMemMap.insert({tmpName, i});
    }

    sort(townMemVec.begin(), townMemVec.end());
    for (int i = 0; i < N; i++)
    {
        townMemMap.insert({townMemVec[i], i});
    }


    cin >> M;
    while(M--)
    {
        string tmpCh, tmpP;
        cin >> tmpCh >> tmpP;

        int idxCh = townMemMap.find(tmpCh)->second;
        int idxP = townMemMap.find(tmpP)->second;

        adj[idxCh].push_back(tmpP);
        ind[idxP]++;
    }

    for (int i = 0; i < N; i++)
    {
        if(ind[i] == 0)
            q.push(i);

        if(adj[i].size() == 0)
            ansRoot.insert(townMemVec[i]);
    }

    while(!q.empty())
    {
        int curIdx = q.front();
        string curName = townMemVec[curIdx];
        q.pop();

        for(auto p : adj[curIdx])
        {
            int curPIdx = townMemMap.find(p)->second;

            for(auto ch : ansChild[curIdx])
            {
                if(ansChild[curPIdx].find(ch) != ansChild[curPIdx].end())
                    ansChild[curPIdx].erase(ch);
            }

            ansChild[curPIdx].insert(curName);
            ind[curPIdx]--;

            if(ind[curPIdx] == 0)
                q.push(curPIdx);
        }
    }

    cout << ansRoot.size() << '\n';
    for(auto t : ansRoot)
    {
        cout << t << ' ';
    }
    cout << '\n';

    for (int i = 0; i < N; i++)
    {
        cout << townMemVec[i] << ' ';
        cout << ansChild[i].size() << ' ';
        
        for(auto t : ansChild[i])
        {
            cout << t << ' ';
        }

        cout << '\n';
    }
}