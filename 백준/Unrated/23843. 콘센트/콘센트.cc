#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 123456789
typedef long long ll;

int N, M;
priority_queue<int> pq;
priority_queue<int, vector<int>, greater<int>> power;

int solve()
{
    for (int i = 0; i < M && !pq.empty(); i++)
    {
        power.push(pq.top());
        pq.pop();
    }
    while (!pq.empty())
    {
        int now = power.top();
        // 콘센트에서 제일 먼저 충전이 끝나는 전자기기들을 제거
        while (!power.empty() && power.top() == now)
        {
            power.pop();
        }
        // 방금 제거한 전자기기들을 충전하는 동안 걸린 시간만큼 시간이 흘렀고 그 이후 부터 다음 전자기기들을 충전하기 시작한다.
        while (!pq.empty() && power.size() < M)
        {
            power.push(now + pq.top()); // 현재 전자기기의 충전이 완료되는 시간을 저장
            pq.pop();
        }
    }
    int ans = 0;
    // 더이상 충전할 전자기기가 없는 경우, 현재 꽂혀있는 기기 중 제일 늦게 끝나는 기기의 종료시간 출력
    while (!power.empty())
    {
        ans = max(ans, power.top());
        power.pop();
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        pq.push(X);
    }
    cout << solve() << "\n";
    return 0;
}
