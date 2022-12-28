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
#define MAX 1000000000
typedef long long ll;

int N, M, S;
vector<int> edge[100001];
bool fanclub[100001], visited[100001];
bool flag = false;

void dfs(int now)
{
    if (fanclub[now])
        return;
    else if (!edge[now].size())
    {
        flag = true;
        return;
    }
    for (int i = 0; i < edge[now].size(); i++)
    {
        int next = edge[now][i];
        dfs(next);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0, U, V; i < M; i++)
    {
        cin >> U >> V;
        edge[U].push_back(V);
    }
    cin >> S;
    for (int i = 0, X; i < S; i++)
    {
        cin >> X;
        fanclub[X] = true;
    }
    dfs(1);
    if (flag)
        cout << "yes\n";
    else
        cout << "Yes\n";
    return 0;
}
