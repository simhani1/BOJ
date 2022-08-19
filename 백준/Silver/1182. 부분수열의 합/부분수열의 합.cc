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

int N, S, cnt = 0;
int arr[21];

void solve(int now, int sum)
{
    // 모든 원소에 대해서 계산을 끝낸 경우(단말노드인 경우)
    if (now == N + 1)
    {
        if (sum == S)
            cnt++;
        return;
    }
    solve(now + 1, sum);            // 현재 원소를 더하지 않는 경우
    solve(now + 1, sum + arr[now]); // 현재 원소를 더하는 경우
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> S;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    solve(1, 0);
    // 모든 원소를 더하지 않는 공집합을 제외시키기
    if (S == 0)
        cnt--;
    cout << cnt;
    return 0;
}
