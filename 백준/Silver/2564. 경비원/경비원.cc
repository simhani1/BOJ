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

int N, M, K;
vector<pair<int, int>> v;
pair<int, int> d;

void input(void)
{
    cin >> N >> M >> K;
    int A, B;
    for (int i = 0; i < K; i++)
    {
        cin >> A >> B;
        v.push_back({A, B});
    }
    cin >> A >> B;
    d = {A, B};
}

void solve(void)
{
    int start = d.first, dist1 = d.second;
    int ans = 0;
    for (auto target : v)
    {
        int end = target.first;
        int dist2 = target.second;
        if (start == end)
            ans += abs(dist1 - dist2);
        else if ((start == 1 && end == 2) || (start == 2 && end == 1))
            ans += min(dist1 + M + dist2, 2 * N + M - dist1 - dist2);
        else if (start == 1 && end == 3)
            ans += (dist1 + dist2);
        else if (start == 1 && end == 4)
            ans += (N - dist1 + dist2);
        else if (start == 2 && end == 3)
            ans += (dist1 + M - dist2);
        else if (start == 2 && end == 4)
            ans += (N - dist1 + M - dist2);
        else if ((start == 3 && end == 4) || (start == 4 && end == 3))
            ans += min(N + dist1 + dist2, 2 * M + N - dist1 - dist2);
        else if (start == 3 && end == 1)
            ans += (dist1 + dist2);
        else if (start == 3 && end == 2)
            ans += (M - dist1 + dist2);
        else if (start == 4 && end == 1)
            ans += (N - dist2 + dist1);
        else if (start == 4 && end == 2)
            ans += (2 * N - dist1 - dist2);
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
