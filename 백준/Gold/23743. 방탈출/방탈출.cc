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

int N, M;
int a, b, c;
priority_queue<pair<int, pair<int, int>>> warp; // 설치시간, 방번호1, 방번호2
vector<int> parentNode;
int parent[200001];
int result = 0;

// 부모 노드 찾기
int Find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if (x != y)
        parent[y] = x;
}

void Kruskal(void)
{
    while (!warp.empty())
    {
        int u = Find(warp.top().second.first);
        int v = Find(warp.top().second.second);
        int cost = -warp.top().first;
        warp.pop();
        // 두 정점의 부모노드가 동일하다면 사이클이 존재하는 것이므로 padd
        if (u == v)
            continue;
        else
        {
            Union(u, v);
            result += cost;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        warp.push(make_pair(-c, make_pair(a, b))); // 기본 오름차순 정렬이므로 설치시간을 음수로 저장
    }
    for (int i = 1; i <= N; i++)
    {
        int exitTime;
        cin >> exitTime;
        warp.push(make_pair(-exitTime, make_pair(0, i))); // 비상 탈출구를 0번이라고 생각하고 간선 추가
        parent[i] = i;
    }
    Kruskal(); // 워프 설치 시간을 계산
    cout << result;
    return 0;
}
