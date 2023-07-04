#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 1234567890
typedef long long ll;

int N, K;
int arr[100001], pSum[100001];

void input(void)
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
}

int check(int target)
{
    int sum = 0, cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += arr[i];
        if (sum >= target)
        {
            sum = 0;
            cnt++;
        }
    }
    return cnt;
}

void solve(void)
{
    int l = 0, r = 2000000;
    int ans = 0;
    while (l <= r)
    {
        int sum = 0;
        int mid = (l + r) / 2;
        int cnt = check(mid);
        if (cnt < K) // 그룹을 더 쪼개야 하므로 점수를 낮춰야함
            r = mid - 1;
        else
        {
            if (cnt == K)
                ans = mid;
            l = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
