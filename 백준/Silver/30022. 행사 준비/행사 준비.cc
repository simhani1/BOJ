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

int N, A, B;
vector<pair<int, pair<int, int>>> v;

void input(void)
{
    cin >> N >> A >> B;
    for (int i = 1, P, Q; i <= N; i++)
    {
        cin >> P >> Q;
        v.push_back({abs(P - Q), {P, Q}});
    }
}

void solve(void)
{
    sort(v.begin(), v.end(), greater<pair<int, pair<int, int>>>());
    ll ans = 0;
    int cntA = 0, cntB = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].second.first < v[i].second.second)
        {
            if (cntA < A)
            {
                ans += v[i].second.first;
                cntA++;
            }
            else
            {
                ans += v[i].second.second;
                cntB++;
            }
        }
        else if (v[i].second.first > v[i].second.second)
        {
            if (cntB < B)
            {
                ans += v[i].second.second;
                cntB++;
            }
            else
            {
                ans += v[i].second.first;
                cntA++;
            }
        }
        else
            ans += v[i].second.first;
    }
    cout << ans << "\n";
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
