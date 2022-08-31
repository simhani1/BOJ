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
pair<int, int> pos[2];
int arr[1001][1001];

int solve(void)
{
    int cnt = 0;
    int startX = min(pos[0].first, pos[1].first);
    int endX = max(pos[0].first, pos[1].first);
    int startY = min(pos[0].second, pos[1].second);
    int endY = max(pos[0].second, pos[1].second);
    int dist = pow(startX - endX, 2) + pow(startY - endY, 2);
    if (dist < 25)
        return 0;
    for (int i = startX; i <= endX; i++)
    {
        for (int j = startY; j <= endY; j++)
        {
            if (arr[i][j] == 1)
                cnt++;
        }
    }
    if (cnt >= 3)
        return 1;
    else
        return 0;
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
            if (arr[i][j] == 2)
                pos[0] = {i, j};
            else if (arr[i][j] == 5)
                pos[1] = {i, j};
        }
    }
    cout << solve() << endl;
    return 0;
}
