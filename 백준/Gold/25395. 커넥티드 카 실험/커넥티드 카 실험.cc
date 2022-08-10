#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <map>
#include <set>
using namespace std;

int N, S;
pair<int, int> car[1000001]; // 현재 위치, 연료
bool connected[1000001];

void connection(int nowCar)
{
    connected[nowCar] = true;
    for (int i = nowCar; i <= N; i++)
    {
        /*
        현재 위치에서 우측으로 갈 수 있는 범위를 탐색
        바로 다음 위치의 차를 포함하지 못하는 경우 탐색 종료
        다음 차의 포함 범위를 탐색
        */
        if (car[nowCar].first + car[nowCar].second >= car[i].first)
        {
            // 커넥티드 카가 아닌 경우 탐색
            if (!connected[i])
                connection(i);
        }
        else
            break;
    }
    for (int i = nowCar; i >= 1; i--)
    {
        if (car[nowCar].first - car[nowCar].second <= car[i].first)
        {
            if (!connected[i])
                connection(i);
        }
        else
            break;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> S;
    for (int i = 1; i <= N; i++)
    {
        cin >> car[i].first;
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> car[i].second;
    }
    connection(S);
    for (int i = 1; i <= N; i++)
    {
        if (connected[i])
            cout << i << " ";
    }
    return 0;
}
