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
#define MOD 987654321
typedef long long ll;

int N, D, K, C;
vector<int> v;
int visited[3001];

void input(void)
{
    cin >> N >> D >> K >> C;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        v.push_back(X);
    }
    for (int i = 0; i < N; i++)
    {
        v.push_back(v[i]);
    }
}

void solve(void)
{
    // 초기화
    int l = 0, ans = 1;
    visited[C]++;
    for (int i = 0; i < K; i++)
    {
        if (!visited[v[i]])
            ans++;
        visited[v[i]]++;
    }
    // start
    int cnt = ans;
    for (int r = K; r < N + K - 1; r++)
    {
        visited[v[l]]--;
        if (!visited[v[l]])
            cnt--;
        l++;
        if (!visited[v[r]])
            cnt++;
        visited[v[r]]++;
        ans = max(ans, cnt);
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
