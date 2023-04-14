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

int N, A;
ll dp[101], num[9];

void makeMaxNum(int X)
{
    vector<int> v;
    if (X % 2 == 0)
    {
        for (int i = 0; i < X / 2; i++)
        {
            v.push_back(1);
        }
    }
    else
    {
        v.push_back(7);
        X -= 3;
        for (int i = 0; i < X / 2; i++)
        {
            v.push_back(1);
        }
    }
    for (auto i : v)
        cout << i;
    cout << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    num[2] = 1;
    num[3] = 7;
    num[4] = 4;
    num[5] = 2;
    num[6] = 0;
    num[7] = 8;
    num[8] = 10;
    fill(dp, dp + 101, 2222222222222222);
    for (int i = 1; i <= 8; i++)
    {
        if (i == 6)
            dp[i] = 6;
        else
            dp[i] = num[i];
    }

    for (int i = 9; i < 101; i++)
    {
        for (int j = 2; j <= 7; j++)
        {
            dp[i] = min(dp[i], dp[i - j] * 10 + num[j]);
        }
    }

    while (N--)
    {
        cin >> A;
        cout << dp[A] << " ";
        makeMaxNum(A);
    }
    return 0;
}
