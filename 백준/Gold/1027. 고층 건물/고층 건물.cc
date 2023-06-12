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

int N;
int arr[51];
int cnt[51];

void printAns(void)
{
    int ans = 0;
    for (auto i : cnt)
    {
        ans = max(ans, i);
    }
    cout << ans << "\n";
}

void solve(void)
{
    for (int i = 0; i < N; i++)
    {
        int nowHeight = arr[i];
        double prevSlope = -INF;
        for (int j = i + 1; j < N; j++)
        {
            int targetHeight = arr[j];
            double nowSlope = double(nowHeight - targetHeight) / double(i - j);
            if (prevSlope < nowSlope)
            {
                prevSlope = nowSlope;
                cnt[i]++;
                cnt[j]++;
            }
        }
    }
}

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    printAns();
    return 0;
}
