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

int N;
int indegree[400001];
map<string, int> m1; // 아이템을 번호로 대체
map<int, string> m2;
vector<vector<int>> tree(400001);
vector<vector<string>> ans(400001);

bool compare(string A, string B)
{
    if (A < B)
        return true;
    else
        return false;
}

void bfs(int idx)
{
    queue<pair<int, int>> q;
    int level = 0, cnt = 0, maxLevel = 0;
    for (int i = 1; i < idx; i++)
    {
        if (!indegree[i])
        {
            q.push({i, level});
            ans[level].push_back(m2[i]);
            cnt++;
        }
    }
    sort(ans[0].begin(), ans[0].end());
    while (!q.empty())
    {
        int now = q.front().first;
        int level = q.front().second;
        q.pop();
        for (auto next : tree[now])
        {
            indegree[next]--;
            if (!indegree[next])
            {
                q.push({next, level + 1});
                ans[level + 1].push_back(m2[next]);
                maxLevel = max(maxLevel, level + 1);
                cnt++;
            }
        }
    }
    if (cnt != idx - 1)
        cout << -1 << endl;
    else
    {
        for (int i = 0; i <= maxLevel; i++)
        {
            sort(ans[i].begin(), ans[i].end());
            for (auto j : ans[i])
            {
                cout << j << "\n";
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int idx = 1;
    for (int i = 0; i < N; i++)
    {
        string A, B;
        cin >> A >> B;
        if (!m1[A])
        {
            m1[A] = idx;
            m2[idx] = A;
            idx++;
        }
        if (!m1[B])
        {
            m1[B] = idx;
            m2[idx] = B;
            idx++;
        }
        tree[m1[A]].push_back(m1[B]);
        indegree[m1[B]]++;
    }
    bfs(idx);
    return 0;
}
