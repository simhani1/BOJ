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
typedef long long ll;

int N, totalSum = 0;
int arr[50001], pSum[50001];

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        totalSum += arr[i];
    }
}

// 누적합 저장
void calcSum(void)
{
    pSum[1] = arr[0];
    for (int i = 2; i < N; i++)
    {
        pSum[i] = pSum[i - 1] + arr[i];
    }
}

void solve(void)
{
    int l = 0, r = 1;
    int ans = 0;
    while (r != N)
    {
        int rightDist = pSum[r] - pSum[l];
        int leftDist = totalSum - rightDist;
        if (rightDist <= leftDist)
        {
            ans = max(ans, rightDist);
            r++;
        }
        else
        {
            ans = max(ans, leftDist);
            l++;
        }
    }
    cout << ans << endl;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    calcSum();
    solve();
    return 0;
}
