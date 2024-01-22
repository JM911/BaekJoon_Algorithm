// 5373. 큐빙
// P5

#include "bits/stdc++.h"
using namespace std;

void setIO(string name = "") 
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin);
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int T, n;
char faceColor[7][6][6];
char IntToFace[7] = {'U', 'D', 'F', 'B', 'L', 'R', 'T'};
unordered_map<char, int> FaceToInt = {{'U', 0}, {'D', 1}, {'F', 2}, {'B', 3}, {'L', 4}, {'R', 5}, {'T', 6}};

vector<int> FaceListU = {3, 5, 2, 4, 3};//{'B', 'R', 'F', 'L', 'B'};
vector<int> FaceListD = {2, 5, 3, 4, 2};//{'F', 'R', 'B', 'L', 'F'};
vector<int> FaceListF = {0, 5, 1, 4, 0};//{'U', 'R', 'D', 'L', 'U'};
vector<int> FaceListB = {0, 4, 1, 5, 0};//{'U', 'L', 'D', 'R', 'U'};
vector<int> FaceListL = {0, 2, 1, 3, 0};//{'U', 'F', 'D', 'B', 'U'};
vector<int> FaceListR = {0, 3, 1, 2, 0};//{'U', 'B', 'D', 'F', 'U'};
unordered_map<char, vector<int>> FaceListMap = {{'U', FaceListU}, {'D', FaceListD}, {'F', FaceListF}, {'B', FaceListB}, {'L', FaceListL}, {'R', FaceListR}};

int GetOppFace(int faceInt)
{
	switch(faceInt)
	{
		case 0: return 1;
		case 1: return 0;
		case 2: return 3;
		case 3: return 2;
		case 4: return 5;
		case 5: return 4;
	}
	return -1;
}

void Init()
{
	for(int face=0; face<6; face++)
	{
		char color;
		switch(face)
		{
			case 0:
				color = 'w';
				break;
			case 1:
				color = 'y';
				break;
			case 2:
				color = 'r';
				break;
			case 3:
				color = 'o';
				break;
			case 4:
				color = 'g';
				break;
			case 5:
				color = 'b';
				break;
		}

		for(int i=0; i<6; i++)
		{
			for(int j=0; j<6; j++)
			{
				faceColor[face][i][j] = color;
			}
		}
	}
}

void MoveSideData(char fromFaceChar, char toFaceChar, char rotFaceChar)
{
	int fromFace = FaceToInt[fromFaceChar];
	int toFace = FaceToInt[toFaceChar];
	int rotFace = FaceToInt[rotFaceChar];
	int fromFaceOpp = GetOppFace(fromFace);
	int toFaceOpp = GetOppFace(toFace);

	faceColor[toFace][rotFace][rotFace] = faceColor[fromFace][rotFace][rotFace];
	faceColor[toFace][fromFace][rotFace] = faceColor[fromFace][toFaceOpp][rotFace];
	faceColor[toFace][rotFace][fromFace] = faceColor[fromFace][rotFace][toFaceOpp];
	faceColor[toFace][fromFaceOpp][rotFace] = faceColor[fromFace][toFace][rotFace];
	faceColor[toFace][rotFace][fromFaceOpp] = faceColor[fromFace][rotFace][toFace];
}

void RotateFace(char rotFace, bool bClock)
{
	char tempColor;
	int rotFaceInt = FaceToInt[rotFace];

	// 1. 꼭지점
	if(bClock)
	{
		tempColor = faceColor[rotFaceInt][FaceListMap[rotFace][3]][FaceListMap[rotFace][4]];
		for(int i=2; i>=0; i--)
		{
			int firstDir = FaceListMap[rotFace][i]; 
			int secondDir = FaceListMap[rotFace][i+1];
			int thirdDir = FaceListMap[rotFace][i+2];
			char moveTargetColor = faceColor[rotFaceInt][firstDir][secondDir];

			faceColor[rotFaceInt][secondDir][thirdDir] = moveTargetColor;
			faceColor[rotFaceInt][thirdDir][secondDir] = moveTargetColor;
		}
		faceColor[rotFaceInt][FaceListMap[rotFace][0]][FaceListMap[rotFace][1]] = tempColor;
		faceColor[rotFaceInt][FaceListMap[rotFace][1]][FaceListMap[rotFace][0]] = tempColor;
	}
	else
	{
		tempColor = faceColor[rotFaceInt][FaceListMap[rotFace][0]][FaceListMap[rotFace][1]];
		for(int i=2; i<=4; i++)
		{
			int firstDir = FaceListMap[rotFace][i]; 
			int secondDir = FaceListMap[rotFace][i-1];
			int thirdDir = FaceListMap[rotFace][i-2];
			char moveTargetColor = faceColor[rotFaceInt][firstDir][secondDir];

			faceColor[rotFaceInt][secondDir][thirdDir] = moveTargetColor;
			faceColor[rotFaceInt][thirdDir][secondDir] = moveTargetColor;
		}
		faceColor[rotFaceInt][FaceListMap[rotFace][4]][FaceListMap[rotFace][3]] = tempColor;
		faceColor[rotFaceInt][FaceListMap[rotFace][3]][FaceListMap[rotFace][4]] = tempColor;
	}

	// 2. 모서리
	if(bClock)
	{
		tempColor = faceColor[rotFaceInt][FaceListMap[rotFace][4]][FaceListMap[rotFace][4]];
		for(int i=3; i>=1; i--)
		{
			int firstDir = FaceListMap[rotFace][i]; 
			int secondDir = FaceListMap[rotFace][i+1];
			char moveTargetColor = faceColor[rotFaceInt][firstDir][firstDir];

			faceColor[rotFaceInt][secondDir][secondDir] = moveTargetColor;
		}
		faceColor[rotFaceInt][FaceListMap[rotFace][1]][FaceListMap[rotFace][1]] = tempColor;
	}
	else
	{
		tempColor = faceColor[rotFaceInt][FaceListMap[rotFace][0]][FaceListMap[rotFace][0]];
		for(int i=1; i<=3; i++)
		{
			int firstDir = FaceListMap[rotFace][i]; 
			int secondDir = FaceListMap[rotFace][i-1];
			char moveTargetColor = faceColor[rotFaceInt][firstDir][firstDir];

			faceColor[rotFaceInt][secondDir][secondDir] = moveTargetColor;
		}
		faceColor[rotFaceInt][FaceListMap[rotFace][3]][FaceListMap[rotFace][3]] = tempColor;
	}

	// 3. 옆면
	if(bClock)
	{
		int tempColorFromFace = FaceListMap[rotFace][3];
		int tempColorToFace = FaceListMap[rotFace][0];
		int tempColorFromFaceOpp = GetOppFace(tempColorFromFace);
		int tempColorToFaceOpp = GetOppFace(tempColorToFace);

		char tempColorLine[3] = {faceColor[tempColorFromFace][rotFaceInt][rotFaceInt], 
								faceColor[tempColorFromFace][rotFaceInt][tempColorToFace], 
								faceColor[tempColorFromFace][rotFaceInt][tempColorToFaceOpp]};
		//MoveSideData(IntToFace[FaceListMap[rotFace][3]], 'T', rotFace);
		for(int i=3; i>=1; i--)
		{
			char fromFaceChar = IntToFace[FaceListMap[rotFace][i-1]];
			char toFaceChar = IntToFace[FaceListMap[rotFace][i]];
			MoveSideData(fromFaceChar, toFaceChar, rotFace);
		}
		faceColor[tempColorToFace][rotFaceInt][rotFaceInt] = tempColorLine[0];
		faceColor[tempColorToFace][rotFaceInt][tempColorFromFaceOpp] = tempColorLine[1];
		faceColor[tempColorToFace][tempColorFromFaceOpp][rotFaceInt] = tempColorLine[1];
		faceColor[tempColorToFace][rotFaceInt][tempColorFromFace] = tempColorLine[2];
		faceColor[tempColorToFace][tempColorFromFace][rotFaceInt] = tempColorLine[2];

		//MoveSideData('T', IntToFace[FaceListMap[rotFace][0]], rotFace);
	}
	else
	{
		int tempColorFromFace = FaceListMap[rotFace][0];
		int tempColorToFace = FaceListMap[rotFace][3];
		int tempColorFromFaceOpp = GetOppFace(tempColorFromFace);
		int tempColorToFaceOpp = GetOppFace(tempColorToFace);

		char tempColorLine[3] = {faceColor[tempColorFromFace][rotFaceInt][rotFaceInt], 
								faceColor[tempColorFromFace][rotFaceInt][tempColorToFace], 
								faceColor[tempColorFromFace][rotFaceInt][tempColorToFaceOpp]};
		//MoveSideData(IntToFace[FaceListMap[rotFace][0]], 'T', rotFace);
		for(int i=0; i<=2; i++)
		{
			char fromFaceChar = IntToFace[FaceListMap[rotFace][i+1]];
			char toFaceChar = IntToFace[FaceListMap[rotFace][i]];
			MoveSideData(fromFaceChar, toFaceChar, rotFace);
		}
		faceColor[tempColorToFace][rotFaceInt][rotFaceInt] = tempColorLine[0];
		faceColor[tempColorToFace][rotFaceInt][tempColorFromFaceOpp] = tempColorLine[1];
		faceColor[tempColorToFace][tempColorFromFaceOpp][rotFaceInt] = tempColorLine[1];
		faceColor[tempColorToFace][rotFaceInt][tempColorFromFace] = tempColorLine[2];
		faceColor[tempColorToFace][tempColorFromFace][rotFaceInt] = tempColorLine[2];
		//MoveSideData('T', IntToFace[FaceListMap[rotFace][3]], rotFace);
	}
}


int main()
{
	setIO("");

	cin >> T;
	while(T--)
	{
		Init();
		cin >> n;

		int u = FaceToInt['U'];
		int l = FaceToInt['L'];
		int r = FaceToInt['R'];
		int b = FaceToInt['B'];
		int f = FaceToInt['F'];

		while(n--)
		{
			string rotData;
			cin >> rotData;
			char rotFace = rotData[0];
			bool bRotClock = rotData[1] == '+' ? true : false;

 			RotateFace(rotFace, bRotClock);
		}

		cout << faceColor[u][b][l] << faceColor[u][b][b] << faceColor[u][b][r] << '\n';
		cout << faceColor[u][l][l] << faceColor[u][u][u] << faceColor[u][r][r] << '\n';
		cout << faceColor[u][f][l] << faceColor[u][f][f] << faceColor[u][f][r] << '\n';
	}
}