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

int T, V, E, cnt = 0, groupNum = 0, result = 0;
int discoveryTime[100001], sccNum[100001], indegree[100001];
bool fin[100001];
vector<int> edge[100001];
stack<int> st;

int getScc(int now)
{
    discoveryTime[now] = ++cnt;
    st.push(now);
    int low = cnt;
    for (int i = 0; i < edge[now].size(); i++)
    {
        int nextNode = edge[now][i];
        if (!discoveryTime[nextNode])
            low = min(low, getScc(nextNode));
        else if (!fin[nextNode])
            low = min(low, discoveryTime[nextNode]);
    }
    if (low == discoveryTime[now])
    {
        while (true)
        {
            int tmp = st.top();
            st.pop();
            fin[tmp] = true;
            sccNum[tmp] = groupNum;
            if (tmp == now)
                break;
        }
        groupNum++;
    }
    return low;
}

void init()
{
    groupNum = 0, result = 0;
    fill(discoveryTime, discoveryTime + 100001, 0);
    fill(sccNum, sccNum + 100001, 0);
    fill(indegree, indegree + 100001, 0);
    fill(fin, fin + 100001, 0);
    for (int i = 0; i < 100001; i++)
    {
        edge[i].clear();
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        init();
        cin >> V >> E;
        for (int i = 0, A, B; i < E; i++)
        {
            cin >> A >> B;
            edge[A].push_back(B);
        }
        for (int i = 1; i <= V; i++)
        {
            if (!fin[i])
                getScc(i);
        }
        for (int i = 1; i <= V; i++)
        {
            for (auto j : edge[i])
            {
                if (sccNum[i] != sccNum[j])
                    indegree[sccNum[j]]++;
            }
        }
        for (int i = 0; i < groupNum; i++)
        {
            if (!indegree[i])
                result++;
        }
        cout << result << "\n";
    }
    return 0;
}
