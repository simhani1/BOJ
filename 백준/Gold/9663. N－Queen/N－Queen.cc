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
#define INF 2147483648
typedef long long ll;

int N, ans = 0;
vector<pair<int, int>> v;
int arr[16]; // 현재 행의 몇전째 열에 퀸이 있는지를 저장

bool check(int x, int y)
{
    for (auto i : v)
    {
        if (i.first == x || i.second == y || abs(i.first - x) == abs(i.second - y))
            return false;
    }
    return true;
}

void solve(int now)
{
    if (now == N)
    {
        ans++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (check(now, i))
        {
            arr[now] = i;
            v.push_back({now, i});
            solve(now + 1);
            v.pop_back();
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    solve(0);
    cout << ans << "\n";
    return 0;
}
