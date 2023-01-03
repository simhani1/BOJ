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
#define MAX 987654321
typedef long long ll;

int N, T;
ll arr[100002];
vector<pair<ll, pair<int, int>>> v;

void imos(void)
{
    // imos 계산 후 누적합까지 계산
    for (int i = 0; i < 2; i++)
    {
        for (int j = 1; j <= 100000; j++)
        {
            arr[j] += arr[j - 1];
        }
    }
}

void check(void)
{
    int l = 0, r = l + T - 1;
    ll ans = -1;
    while (r != 100001)
    {
        ll tmp;
        if (l == 0)
            tmp = arr[r];
        else
            tmp = arr[r] - arr[l - 1];
        if (ans < tmp)
        {
            ans = tmp;
            v.push_back({ans, {l, r + 1}});
        }
        l++;
        r++;
    }
    sort(v.begin(), v.end(), greater<pair<ll, pair<int, int>>>());
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> T;
    for (int i = 0, K; i < N; i++)
    {
        cin >> K;
        for (int j = 0, S, T; j < K; j++)
        {
            cin >> S >> T;
            arr[S]++;
            arr[T]--;
        }
    }
    imos();
    check();
    cout << v[0].second.first << " " << v[0].second.second << "\n";
    return 0;
}
