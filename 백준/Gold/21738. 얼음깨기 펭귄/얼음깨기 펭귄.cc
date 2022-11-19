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
typedef long long ll;
typedef pair<int, int> pii;

int N, S, P;
vector<int> v[328001], ans;
bool visited[328001], support[328001];

void dfs(int now, int cnt)
{
    visited[now] = true;
    if (support[now])
        ans.push_back(cnt);
    for (int i = 0; i < v[now].size(); i++)
    {
        int next = v[now][i];
        if (!visited[next])
        {
            dfs(next, cnt + 1);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> S >> P;
    for (int i = 1, A, B; i < N; i++)
    {
        cin >> A >> B;
        v[A].push_back(B);
        v[B].push_back(A);
    }
    for (int i = 1; i <= S; i++)
    {
        support[i] = true;
    }
    dfs(P, 0);
    sort(ans.begin(), ans.end());
    cout << N - (ans[0] + ans[1] + 1) << endl;
    return 0;
}
