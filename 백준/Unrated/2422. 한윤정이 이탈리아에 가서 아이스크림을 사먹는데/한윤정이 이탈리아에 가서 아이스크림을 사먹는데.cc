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
#define INF 2147483648
typedef long long ll;

int N, M, ans = 0;
vector<int> v[201];
int visited[201];

void solve(int idx, int cnt)
{
    if (cnt == 3)
    {
        ans++;
        return;
    }
    for (int i = idx; i <= N; i++)
    {
        if (visited[i] == 0)
        {
            visited[i]++;
            for (int j = 0; j < v[i].size(); j++)
            {
                visited[v[i][j]]++;
            }
            solve(i + 1, cnt + 1);
            visited[i]--;
            for (int j = 0; j < v[i].size(); j++)
            {
                visited[v[i][j]]--;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0, A, B; i < M; i++)
    {
        cin >> A >> B;
        v[min(A, B)].push_back(max(A, B));
    }
    solve(1, 0);
    cout << ans << "\n";
    return 0;
}
