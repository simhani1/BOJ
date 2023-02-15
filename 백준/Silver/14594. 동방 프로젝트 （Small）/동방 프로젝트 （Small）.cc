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
int parent[101];

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
    int cnt = 1;
    for (int i = 1; i < N; i++)
    {
        if (Find(i) != Find(i + 1))
            cnt++;
    }
    return cnt;
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
        for (int j = X + 1; j <= Y; j++)
        {
            Union(X, j);
        }
    }
    cout << countSet() << "\n";
    return 0;
}
