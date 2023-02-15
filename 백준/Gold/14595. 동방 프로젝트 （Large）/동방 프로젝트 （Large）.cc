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
#define INF 1234567890
typedef long long ll;

int N, M;
int parent[1000001];
bool visited[1000001];
vector<pair<int, int>> v;

int Find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x == y)
        return;
    parent[y] = x;
}

int countSet(void)
{
    int cnt = 0;
    for (int i = 1; i <= N; i++)
    {
        int p = Find(i);
        if (!visited[p])
        {
            visited[p] = true;
            cnt++;
        }
    }
    return cnt;
}

int solve(void)
{
    int prev = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int left = v[i].first;
        int right = v[i].second;
        left = max(left, prev);
        for (int j = left; j <= right; j++)
        {
            Union(left, j);
        }
        prev = max(prev, right);
    }
    return countSet();
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    cin >> M;
    for (int i = 0, X, Y; i < M; i++)
    {
        cin >> X >> Y;
        v.push_back({X, Y});
    }
    sort(v.begin(), v.end());
    cout << solve() << "\n";
    return 0;
}
