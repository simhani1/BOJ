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

int V, E, cnt = 0;
int discoverTime[10001];
vector<vector<int>> ans;
vector<int> node[10001];
stack<int> st;
bool fin[10001];

int getSCC(int now)
{
    discoverTime[now] = ++cnt;
    st.push(now);
    int low = cnt;
    for (int i = 0; i < node[now].size(); i++)
    {
        int next = node[now][i];
        if (!discoverTime[next])
            low = min(low, getSCC(next));
        else if (!fin[next])
            low = min(low, discoverTime[next]);
    }
    // 리더노드와 방문시간이 같은 경우 SCC 집합에 추가
    if (low == discoverTime[now])
    {
        vector<int> scc;
        while (true)
        {
            int tmp = st.top();
            st.pop();
            scc.push_back(tmp);
            fin[tmp] = true;
            if (tmp == now)
                break;
        }
        ans.push_back(scc);
    }
    return low;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;
    for (int i = 0, A, B; i < E; i++)
    {
        cin >> A >> B;
        node[A].push_back(B);
    }
    for (int i = 1; i <= V; i++)
    {
        if (!fin[i])
            getSCC(i);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        sort(ans[i].begin(), ans[i].end());
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << -1 << endl;
    }
    return 0;
}
