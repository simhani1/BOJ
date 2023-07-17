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
#define INF 2000000000
typedef long long ll;

int N, M;
int parent[10001];
vector<pair<int, pair<int, int>>> v;

int Find(int X)
{
    if (X == parent[X])
        return X;
    return parent[X] = Find(parent[X]);
}

void Union(int X, int Y)
{
    X = Find(X);
    Y = Find(Y);
    if (X != Y)
        parent[max(X, Y)] = min(X, Y);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }
    for (int i = 0, A, B, C, D; i < M; i++)
    {
        cin >> A >> B >> C >> D;
        sum += C;
        if (D)
        {
            Union(A, B);
            sum -= C;
        }
        else
            v.push_back({-C, {A, B}});
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int cost = -v[i].first;
        int A = Find(v[i].second.first);
        int B = Find(v[i].second.second);
        if (A != B)
        {
            sum -= cost;
            Union(A, B);
        }
    }
    cout << sum << "\n";
    return 0;
}
