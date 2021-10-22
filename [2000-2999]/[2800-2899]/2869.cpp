// 2869. 달팽이는 올라가고 싶다.
// B1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main()
{
    int A, B, V;
    cin >> A >> B >> V;

    int oneDay = A - B; // 낮+밤 하루 이동거리
    int beforeLastDay = V - A; // 마지막 날은 미끄러지지 않으므로 A만큼 오름. 그 전까지 가야하는 거리
    int day = beforeLastDay / oneDay; // 마지막 날 전까지 필요한 시간

    if (beforeLastDay % oneDay > 0) // 1미터라도 남는다면 하루 더 올라가야함
        day++;

    day++; // 마지막 날
    cout << day;

    return 0;
}
