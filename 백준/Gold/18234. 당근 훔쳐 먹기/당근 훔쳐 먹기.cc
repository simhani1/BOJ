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
#define INF 987654321
#define INIT 100000000
typedef long long ll;

ll N, T;
ll sum = 0;
vector<ll> v;

ll solve(void)
{
    for (ll i = 1; i <= N; i++)
    {
        sum += (v[i - 1] * (T - i));
    }
    return sum;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> T;
    for (ll i = 0, A, B; i < N; i++)
    {
        cin >> A >> B;
        sum += A;
        v.push_back(B);
    }
    sort(v.begin(), v.end(), greater<>());
    cout << solve() << "\n";
    return 0;
}
