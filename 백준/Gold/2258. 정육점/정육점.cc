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
#define INF 2147483648
typedef long long ll;

ll N, M;
vector<pair<int, int>> v;

bool comp(pair<int, int> X, pair<int, int> Y)
{
    if (X.first == Y.first)
        return X.second > Y.second;
    return X.first < Y.first;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0, A, B; i < N; i++)
    {
        cin >> A >> B;
        v.push_back({B, A});
    }
    sort(v.begin(), v.end(), comp);
    ll ans = INF, weight = 0, price = -1;
    bool flag = false;
    for (int i = 0; i < v.size(); i++)
    {
        weight += v[i].second;
        if (i > 0 && v[i].first == v[i - 1].first)
            price += v[i].first;
        else
            price = v[i].first;
        if (weight >= M)
            ans = min(ans, price);
    }
    (ans == INF) ? cout << -1 << "\n" : cout << ans << "\n";
    return 0;
}
