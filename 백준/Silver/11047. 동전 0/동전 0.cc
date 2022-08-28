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

int N, K, cnt = 0;
vector<int> v;

void solve(void)
{
    for (int i = 0; i < N; i++)
    {
        int coin = v[i];
        if (K == 0)
            return;
        if (coin > K)
            continue;
        cnt += (K / coin);
        K %= coin;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 0, A; i < N; i++)
    {
        cin >> A;
        v.push_back(A);
    }
    sort(v.begin(), v.end(), greater<int>());
    solve();
    cout << cnt;
    return 0;
}