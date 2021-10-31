// 1620. 나는야 포켓몬 마스터 이다솜
// S4

#include <bits/stdc++.h>
using namespace std;

bool strComp(pair<int,string> p1, pair<int,string> p2)
{
    string s1 = p1.second;
    string s2 = p2.second;

    if(s1.compare(s2)<0)
        return true;
    return false;
}

int SearchName(vector<pair<int,string>> &nameArr, int start, int end, string targetName)
{
    int mid = (start + end) / 2;
    string midName = nameArr[mid].second;

    if (targetName.compare(midName) > 0)
        return SearchName(nameArr, mid+1, end, targetName);
    else if (targetName.compare(midName) < 0)
        return SearchName(nameArr, start, mid-1, targetName);
    else
        return nameArr[mid].first;
}

int main()
{
    int N, M;
    cin >> N >> M;

    string* pedia = new string[N];
    vector<pair<int, string>> v;
    char temp[30];

    for(int i=0; i<N; i++)
    {
        scanf("%s", temp);
        pedia[i] = temp;
        v.push_back(pair<int, string>(i, temp));
    }

    sort(v.begin(), v.end(), strComp);

    string target;
    int num;

    for(int i=0; i<M; i++)
    {
        scanf("%s", temp);
        target = temp;
        if(target[0]>='0' && target[0]<='9')
        {
            num = stoi(target);
            //cout << pedia[num-1] << '\n';
            printf("%s\n", pedia[num-1].c_str());
        }
        else
        {
            num = SearchName(v, 0, N-1, target);
            //cout << num + 1 << '\n';
            printf("%d\n", num+1);
        }
    }

    delete[] pedia;

    return 0;
}
