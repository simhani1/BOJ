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

int arr[6][6];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
set<string> ans;

void dfs(int x, int y, string str, int length)
{
    if (length == 6)
    {
        ans.insert(str);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        string nextStr = str + to_string(arr[nextX][nextY]);
        if (0 <= nextX && nextX < 5 && 0 <= nextY && nextY < 5)
            dfs(nextX, nextY, nextStr, length + 1);
    }
    return;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            string now = to_string(arr[i][j]);
            dfs(i, j, now, 1);
        }
    }
    cout << ans.size() << endl;
    return 0;
}