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
#define INF 123456789
typedef long long ll;

int N, M;
int arr[101][101];
vector<vector<int>> v;

void input(void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }
}

void firstDraw(int i)
{
    for (int j = 0; j < M; j++)
    {
        if (arr[i][j] == 0)
            continue;
        arr[i][j]--;
    }
}

void makingGroup(void)
{
    for (int i = 0; i < N; i++)
    {
        vector<int> tmp;
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] != 0)
                tmp.push_back(arr[i][j]);
            else
            {
                if (tmp.size() == 0)
                    continue;
                v.push_back(tmp);
                tmp.clear();
            }
        }
        if (tmp.size())
        {
            v.push_back(tmp);
            tmp.clear();
        }
    }
}

int calc(int color[])
{
    if (color[1] && color[2])
        return min(color[1], color[2]) + 1;
    else if (color[1] && !color[2])
        return color[1];
    else if (!color[1] && color[2])
        return color[2];
    return 0;
}

int solve(void)
{
    int ans = 0;
    int color[3];
    for (auto tmp : v)
    {
        int prev = tmp[0];
        fill(color, color + 3, 0);
        color[prev]++;
        for (int i = 1; i < tmp.size(); i++)
        {
            if (tmp[i] == prev)
                continue;
            color[tmp[i]]++;
            prev = tmp[i];
        }
        ans += calc(color);
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    makingGroup();
    cout << solve() << "\n";
    return 0;
}
