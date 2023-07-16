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
int parent[200001];
priority_queue<pair<int, pair<int, int>>> pq;

int Find(int X)
{
    if (parent[X] == X)
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

bool isSameParent(int X, int Y)
{
    return Find(X) == Find(Y);
}

void init(void)
{
    for (int i = 0; i < 200001; i++)
    {
        parent[i] = i;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        cin >> M >> N;
        if (!M && !N)
            break;
        init();
        int sum = 0;
        for (int i = 0, X, Y, Z; i < N; i++)
        {
            cin >> X >> Y >> Z;
            sum += Z;
            pq.push({-Z, {X, Y}});
        }
        while (!pq.empty())
        {
            int cost = -pq.top().first;
            int from = pq.top().second.first;
            int to = pq.top().second.second;
            pq.pop();
            if (!isSameParent(from, to))
            {
                sum -= cost;
                Union(from, to);
            }
        }
        cout << sum << "\n";
    }
    return 0;
}
