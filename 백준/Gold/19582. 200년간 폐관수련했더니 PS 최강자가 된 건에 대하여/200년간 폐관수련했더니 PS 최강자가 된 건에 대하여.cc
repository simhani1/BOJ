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
#include <sstream>
#include <cmath>
using namespace std;
#define INF 1e15
#define MOD 1000000
typedef long long ll;

int N;
ll arr[2][100001], minLimit[100001];

void findMinLimit(void)
{
    ll tmp = INF;
    minLimit[N - 1] = arr[0][N - 1];
    for (int i = N - 1; i >= 1; i--)
    {
        tmp = min(tmp, arr[0][i]);
        minLimit[i - 1] = tmp;
    }
}

void solve(void)
{
    findMinLimit();
    ll cnt = 0, pSum = 0, maxNum = 0;
    for (int i = 0; i < N; i++)
    {
        maxNum = max(maxNum, arr[1][i]);
        // 지금까지의 누적 합 <= 이후 상한값의 최소
        if (pSum <= arr[0][i])
            pSum += arr[1][i];
        else
        {
            if (pSum - maxNum <= arr[0][i])
            {
                pSum -= maxNum;
                pSum += arr[1][i];
            }
            cnt++;
        }
    }
    (cnt <= 1) ? cout << "Kkeo-eok"
                      << "\n"
               : cout << "Zzz"
                      << "\n";
}

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[0][i] >> arr[1][i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
