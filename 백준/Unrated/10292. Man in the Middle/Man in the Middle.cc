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
#define INF 123456789
typedef long long ll;

int T, V, E, seq = 0, ans = 0;
int discovered[30001]; // DFS 탐색 순서 저장
bool point[30001];
vector<int> edge[30001];

int dfs(int now, int isRoot)
{
    discovered[now] = ++seq;
    int ret = discovered[now]; // 인접 노드들의 노드 중 도달 가능한 제일 높은 높이 저장
    int child = 0;             // now가 루트노드인 경우 자식 수가 2 이상인지 확인하기 위한 용도
    for (int i = 0; i < edge[now].size(); i++)
    {
        int nextNode = edge[now][i];
        if (!discovered[nextNode]) // 다음 노드를 아직 방문하지 않은 경우
        {
            child++;
            int low = dfs(nextNode, false);        // 현재 노드의 자식 노드가 방문가능한 노드의 최고 도달 깊이
            if (!isRoot && low >= discovered[now]) // 루트노드가 아니고 자식노드가 현재 노드보다 더 높은 높이에 도달 불가능한 경우
                point[now] = true;
            ret = min(ret, low);
        }
        else
            ret = min(ret, discovered[nextNode]);
    }
    if (isRoot && 2 <= child)
        point[now] = true;
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        bool flag = false;
        cin >> V >> E;
        for (int i = 0, A, B; i < E; i++)
        {
            cin >> A >> B;
            edge[A].push_back(B);
            edge[B].push_back(A);
        }
        for (int i = 1; i <= V; i++)
        {
            if (!discovered[i])
                dfs(i, true);
        }
        for (int i = 1; i <= V; i++)
        {
            if (point[i])
            {
                flag = true;
                break;
            }
        }
        flag ? cout << "YES\n" : cout << "NO\n";
        for (int i = 0; i < 30001; i++)
            edge[i].clear();
        fill(discovered, discovered + 30001, 0);
        fill(point, point + 30001, false);
    }
    return 0;
}
