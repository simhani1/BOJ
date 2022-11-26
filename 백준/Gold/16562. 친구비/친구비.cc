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
#define MAX 123456789
typedef long long ll;

int N, M, K, ans = 0;
int parent[10001], price[10001];
bool visited[10001];

int Find(int target)
{
    if (parent[target] == target)
        return target;
    return parent[target] = Find(parent[target]);
}

void Union(int V, int W)
{
    V = Find(V);
    W = Find(W);
    if (V != W)
    {
        if (price[V] <= price[W])
            parent[W] = V;
        else
            parent[V] = W;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> price[i];
        parent[i] = i;
    }
    for (int i = 0, V, W; i < M; i++)
    {
        cin >> V >> W;
        Union(V, W);
    }
    for (int i = 1, now; i <= N; i++)
    {
        now = Find(i);
        if (!visited[now])
        {
            visited[now] = true;
            ans += price[now];
        }
    }
    if (ans > K)
        cout << "Oh no" << endl;
    else
        cout << ans << endl;
    return 0;
}
