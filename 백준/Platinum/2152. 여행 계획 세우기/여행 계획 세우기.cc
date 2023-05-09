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

int V, E, S, T, start, target, cnt = 0, sccCnt = 1;
int discoverTime[10001], scc[10001], country[10001], res[10001];
vector<int> node[10001], sccNode[10001];
stack<int> st;

int getSCC(int now)
{
    discoverTime[now] = ++cnt;
    st.push(now);
    int low = discoverTime[now];
    for (int i = 0; i < node[now].size(); i++)
    {
        int next = node[now][i];
        if (discoverTime[next] == -1)
            low = min(low, getSCC(next));
        else if (scc[next] == -1)
            low = min(low, discoverTime[next]);
    }
    if (low == discoverTime[now])
    {
        while (true)
        {
            int tmp = st.top();
            st.pop();
            // 시작점, 도착점이 속한 scc그룹의 번호를 start, target에 저장
            // 각 scc 그룹에 속한 전체 노드의 수를 배열에 저장
            if (tmp == S)
                start = sccCnt;
            if (tmp == T)
                target = sccCnt;
            scc[tmp] = sccCnt;
            country[sccCnt] += 1;
            if (tmp == now)
                break;
        }
        sccCnt++;
    }
    return low;
}

void bfs()
{
    queue<int> q;
    q.push(start);
    res[start] = country[start];
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < sccNode[now].size(); i++)
        {
            int next = sccNode[now][i];
            if (res[next] < res[now] + country[next])
            {
                res[next] = res[now] + country[next];
                q.push(next);
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E >> S >> T;
    for (int i = 0, A, B; i < E; i++)
    {
        cin >> A >> B;
        node[A].push_back(B);
    }
    fill(discoverTime, discoverTime + 10001, -1);
    fill(scc, scc + 10001, -1);
    for (int i = 1; i <= V; i++)
    {
        if (discoverTime[i] == -1)
            getSCC(i);
    }

    for (int now = 1; now <= V; now++)
    {
        for (int j = 0; j < node[now].size(); j++)
        {
            int next = scc[node[now][j]];
            if (scc[now] != next)
                sccNode[scc[now]].push_back(next);
        }
    }
    if (start == target)
    {
        cout << country[start] << "\n";
        return 0;
    }
    bfs();
    cout << res[target] << "\n";
    return 0;
}
