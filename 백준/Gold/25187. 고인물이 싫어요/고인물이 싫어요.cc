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
#define MAX 1000000007
typedef long long ll;

int N, M, Q, cnt1, cnt2;
int arr[100001], parent[100001];
vector<int> edge[200001];
bool visited[100001];
map<int, int> ans;
set<pair<int, int>> s;

void dfs(int now, int next)
{
    visited[next] = true;
    parent[next] = now;
    if (arr[next])
        cnt1++;
    else
        cnt2++;
    for (int i = 0; i < edge[next].size(); i++)
    {
        int nextNode = edge[next][i];
        if (!visited[nextNode])
            dfs(now, nextNode);
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        parent[i] = i;
    }
    for (int i = 0, A, B; i < M; i++)
    {
        cin >> A >> B;
        edge[A].push_back(B);
        edge[B].push_back(A);
    }
    for (int i = 1; i <= N; i++)
    {
        cnt1 = 0;
        cnt2 = 0;
        if (!visited[i])
        {
            dfs(i, i);
            if (cnt1 > cnt2)
                ans[i] = 1;
            else
                ans[i] = 0;
        }
    }
    for (int i = 0, K; i < Q; i++)
    {
        cin >> K;
        cout << ans[parent[K]] << "\n";
    }
    return 0;
}
