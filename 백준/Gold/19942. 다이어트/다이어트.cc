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
#define INF 123456789
typedef long long ll;

int N, A = 0, B = 0, C = 0, D = 0, E = 0;
int minValue[4];
int arr[16][5];
bool visited[16];
int minCost = INF;
vector<vector<int>> ans;

bool check(void)
{
    if (A >= minValue[0] && B >= minValue[1] && C >= minValue[2] && D >= minValue[3])
        return true;
    return false;
}

void solve(int idx, int money)
{
    if (check())
    {
        vector<int> tmp;
        tmp.push_back(money);
        for (int i = 0; i < N; i++)
        {
            if (visited[i])
                tmp.push_back(i + 1);
        }
        ans.push_back(tmp);
        return;
    }
    for (int i = idx; i < N; i++)
    {
        if (!visited[i])
        {
            A += arr[i][0];
            B += arr[i][1];
            C += arr[i][2];
            D += arr[i][3];
            E += arr[i][4];
            visited[i] = true;
            solve(i, E);
            A -= arr[i][0];
            B -= arr[i][1];
            C -= arr[i][2];
            D -= arr[i][3];
            E -= arr[i][4];
            visited[i] = false;
        }
    }
}

void input(void)
{
    cin >> N;
    for (int i = 0; i < 4; i++)
    {
        cin >> minValue[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve(0, 0);
    int minCost = INF;
    if (ans.size() == 0)
        cout << -1 << "\n";
    else
    {
        sort(ans.begin(), ans.end());
        cout << ans[0][0] << endl;
        for (int i = 1; i < ans[0].size(); i++)
        {
            cout << ans[0][i] << " ";
        }
    }
    return 0;
}
