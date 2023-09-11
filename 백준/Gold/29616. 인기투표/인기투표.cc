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
#define INF 123456789
#define MOD 1000000
typedef long long ll;

ll N, M;
ll past[101], now[101], pastRatio[101], nowRatio[101];

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll gcdN(ll arr[])
{
    ll a = arr[0];
    for (int i = 0; i < N; i++)
    {
        a = gcd(a, arr[i]);
    }
    return a;
}

void solve(void)
{
    ll ansPast = 0, ansNow = 0;
    ll gcdPast = gcdN(past);
    ll gcdNow = gcdN(now);
    // 최소 공약수로 약분
    for (int i = 0; i < N; i++)
    {
        past[i] /= gcdPast;
        now[i] /= gcdNow;
        ansPast += past[i];
        ansNow += now[i];
    }
    ll mul = 1;
    for (int i = 0; i < N; i++)
    {
        if (past[i] < now[i])
            continue;
        if (now[i] == 0)
            continue;
        ll q = past[i] / now[i];
        ll r = past[i] % now[i];
        if (r == 0)
            mul = max(mul, q);
        else
            mul = max(mul, q + 1);
    }
    ansNow *= mul;
    cout << ansPast << " " << ansNow << "\n";
}

void input(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> past[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> now[i];
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
