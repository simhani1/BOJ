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

int N, M, P, Q;
bool visited[10001];
set<pair<int, int>> ans;
vector<pair<int, int>> node[10001];
priority_queue<pair<int, pair<int, int>>> pq;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> N >> M >> P >> Q;
        for (int i = 0, U, V, W; i < M; i++)
        {
            cin >> U >> V >> W;
            node[U].push_back({V, W});
            node[V].push_back({U, W});
        }
        pq.push({0, {1, 1}});
        while (!pq.empty())
        {
            int cost = -pq.top().first;
            int from = pq.top().second.first;
            int to = pq.top().second.second;
            pq.pop();
            if (!visited[to])
            {
                ans.insert({from, to});
                ans.insert({to, from});
                visited[to] = true;
                for (int i = 0; i < node[to].size(); i++)
                {
                    int nextCost = node[to][i].second;
                    int next = node[to][i].first;
                    if (!visited[next])
                        pq.push({-nextCost, {to, next}});
                }
            }
        }
        set<pair<int, int>>::iterator iter = ans.find({P, Q});
        if (iter != ans.end())
            cout << "YES\n";
        else
            cout << "NO\n";
        ans.clear();
        for (int i = 0; i <= N; i++)
        {
            visited[i] = false;
            node[i].clear();
        }
    }
    return 0;
}
