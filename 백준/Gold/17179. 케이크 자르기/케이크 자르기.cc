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
#define INF 123456789
#define MAX 2000000000
typedef long long ll;

int N, M, L;
int arr[1001];

int check(int mid)
{
    int cnt = 0, prev = 0;
    for (int i = 0; i <= M; i++)
    {
        if (arr[i] - prev >= mid)
        {
            cnt++;
            prev = arr[i];
        }
    }
    return cnt;
}

int solve(int target)
{
    int l = 1, r = L, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int cut = check(mid);
        // 제일 마지막 조각이 mid보다 커야 하므로 arr[M]-prev 값이 mid보다 큰 경우에 정답 갱신
        // 따라서 target보다 큰 경우에만 정답을 갱신하면 된다.
        if (cut > target)
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return r;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> L;
    for (int i = 0; i < M; i++)
    {
        cin >> arr[i];
    }
    arr[M] = L;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        cout << solve(X) << "\n";
    }
    return 0;
}
