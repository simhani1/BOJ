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

int N, m, M, T, R;
int minute, pulse;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> m >> M >> T >> R;
    if (M - m < T) // 초기상태에서 운동이 불가할 경우
    {
        cout << -1;
        return 0;
    }
    pulse = m;
    while (1)
    {
        if (pulse + T <= M)
        {
            pulse += T;
            N--;
        }
        else
        {
            pulse -= R;
            if (pulse < m)
                pulse = m;
        }
        minute++; // 운동 또는 휴식에 소요된 시간
        if (N == 0)
        {
            cout << minute;
            return 0;
        }
    }
    return 0;
}
