// 7432. 디스크 트리
// G3

#define FASTIO cin.tie(nullptr); ios_base::sync_with_stdio(false)
#include "bits/stdc++.h"
using namespace std;

set<string> Roots;
unordered_map<string, set<string>> c;

void ParsePath(const string& path)
{
	string curFolder = "";
	string prevFolder = "";

	for(int i=0; i<=path.size(); i++)
	{
		if(i == path.size() || path[i] == '\\')
		{
			if(prevFolder == "")
				Roots.insert(curFolder);
			else
				c[prevFolder].insert(curFolder);
			prevFolder = curFolder;
			curFolder += '\\';
			continue;
		}
		
		curFolder += path[i];
	}
}

void PrintFolderOnly(const string& path)
{
	int len = path.size();
	int i = len - 1;

	stack<char> s;
	while(i>=0 && path[i] != '\\')
		s.push(path[i--]);
	
	while(!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

void DFS(const string& curFolder, int step)
{
	if(curFolder == "")
	{
		for(auto elem : Roots)
		{
			// cout << elem << '\n';
			PrintFolderOnly(elem);
			cout << '\n';
			DFS(elem, step+1);
		}
		return;
	}

	if(c.count(curFolder) == 0)
		return;

	for(auto elem : c[curFolder])
	{
		// 공백
		string space = "";
		for(int i=0; i<step; i++)
			space += ' ';
		cout << space;

		//cout << elem << '\n';
		PrintFolderOnly(elem);
		cout << '\n';
		DFS(elem, step+1);
	}
}

int main()
{
	FASTIO;

	int N;
	cin >> N;
	while(N--)
	{
		string s;
		cin >> s;
		ParsePath(s);
	}

	DFS("", 0);
}