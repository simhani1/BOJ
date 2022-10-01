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

int N, cnt = 0, ans = 0;
int cost[101], discoverTime[101];
vector<int> node[101];
stack<int> st;
bool fin[101];

int getSCC(int now)
{
    discoverTime[now] = ++cnt;
    st.push(now);
    int low = discoverTime[now];
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
        int minCost = 1e9;
        while (true)
        {
            int tmp = st.top();
            st.pop();
            fin[tmp] = true;
            minCost = min(minCost, cost[tmp]);
            if (tmp == now) // scc 집합 원소를 모두 확인한 경우 중단
                break;
        }
        ans += minCost;
    }
    return low;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
    }
    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
        {
            if (s[j] == '1')
                node[i].push_back(j + 1);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (!fin[i])
            getSCC(i);
    }
    cout << ans << endl;
    return 0;
}
