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
#define MAX 1000000007
typedef long long ll;

int N, cnt = 0;
int arr[101][101];
vector<vector<int>> v;
vector<int> tmp;
bool visited[101];

void solve(void)
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (arr[i][j] != arr[j][i])
            {
                cout << 0 << endl;
                return;
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            cnt++;
            tmp.push_back(i);
            for (int j = 1; j <= N; j++)
            {
                if (!arr[i][j] && i != j)
                {
                    visited[j] = true;
                    tmp.push_back(j);
                }
            }
            v.push_back(tmp);
            tmp.clear();
        }
    }
    bool flag = true;
    for (int i = 0; i < cnt; i++)
    {
        if (v[i].size() == 1)
        {
            flag = false;
            break;
        }
    }
    if (!flag)
        cout << 0 << endl;
    else
    {
        cout << cnt << endl;
        for (int i = 0; i < cnt; i++)
        {
            for (auto j : v[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> arr[i][j];
        }
    }
    solve();
    return 0;
}
