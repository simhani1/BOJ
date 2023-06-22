#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 1234567890
typedef long long ll;

int N;
int arr[500001], ans[500001];

void printAns(void)
{
    for (int i = 1; i <= N; i++)
    {
        cout << ans[i] << " ";
    }
}

void solve(void)
{
    stack<pair<int, int>> st;
    for (int i = 1; i <= N; i++)
    {
        int now = arr[i];
        int nowIdx = i;
        while (!st.empty())
        {
            int before = st.top().first;
            int beforeIdx = st.top().second;
            if (before < now)
                st.pop();
            else
            {
                st.push({now, nowIdx});
                ans[nowIdx] = beforeIdx;
                break;
            }
        }
        if (st.empty())
        {
            ans[nowIdx] = 0;
            st.push({now, nowIdx});
        }
    }
}

void input(void)
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    printAns();
    return 0;
}
