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
vector<int> node[501];
int indegree[501], t[501], maxT[501];

void solve(void)
{
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (!indegree[i]){
            q.push(i);
            maxT[i]=t[i];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        int now = q.front();
        q.pop();
        for (int j = 0; j < node[now].size(); j++)
        {
            int next = node[now][j];
            indegree[next]--;
            // 앞 건물 건설시간 중 최장 시간 + 현재 건물 건설시간
            maxT[next] = max(maxT[next], t[next]+maxT[now]); 
            if (!indegree[next])
                q.push(next);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1, A; i <= N; i++)
    {
        cin >> A;
        t[i] = A;
        while (true)
        {
            cin >> A;
            if (A == -1)
                break;
            node[A].push_back(i);
            indegree[i]++;
        }
    }
    solve();
    for (int i = 1; i <= N; i++)
    {
        cout << maxT[i] << endl;
    }
    return 0;
}
