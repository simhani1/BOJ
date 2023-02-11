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

int A, B, C;
bool visited[201][201][201];
set<int> ans;

void dfs(int a, int b, int c)
{
    if (a == 0)
        ans.insert(c);
    if (!visited[a][b][c])
    {
        visited[a][b][c] = true;
        if (a != 0)
        {
            if (B - b <= a)
                dfs(a - B + b, B, c);
            else
                dfs(0, a + b, c);
            if (C - c <= a)
                dfs(a - C + c, b, C);
            else
                dfs(0, b, a + c);
        }
        if (b != 0)
        {
            if (A - a <= b)
                dfs(A, b - A + a, c);
            else
                dfs(a + b, 0, c);
            if (C - c <= b)
                dfs(a, b - C + c, C);
            else
                dfs(a, 0, c + b);
        }
        if (c != 0)
        {
            if (A - a <= c)
                dfs(A, b, c - A + a);
            else
                dfs(a + c, b, 0);
            if (B - b <= c)
                dfs(a, B, c - B + b);
            else
                dfs(a, b + c, 0);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B >> C;
    dfs(0, 0, C);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}
