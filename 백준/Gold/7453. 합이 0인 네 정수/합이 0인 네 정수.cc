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
int A[4001], B[4001], C[4001], D[4001];
vector<int> v1, v2;

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            v1.push_back(A[i] + B[j]);
            v2.push_back(C[i] + D[j]);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
}

void solve(void)
{
    ll ans = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        int now = v1[i];
        int leftIdx = lower_bound(v2.begin(), v2.end(), -now) - v2.begin();
        int rightIdx = upper_bound(v2.begin(), v2.end(), -now) - v2.begin();
        ans += (ll) rightIdx - leftIdx;
    }
    cout << ans << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
