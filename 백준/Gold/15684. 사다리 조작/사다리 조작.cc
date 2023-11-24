#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;
#define INF 2100000000
#define MOD 987654321
typedef long long ll;

int N, M, H, ans = INF;
bool check[35][35];

void input(void)
{
    cin >> N >> M >> H;
    for (int i = 0, A, B; i < M; i++)
    {
        cin >> A >> B;
        check[A][B] = true; // A번째에서 B -> B+1 로 가는 길이 있음
    }
}

bool isAnswer(void)
{
    for (int j = 1; j <= N; j++)
    {
        int start = j;
        for (int i = 1; i <= H; i++)
        {
            if (start + 1 <= N && check[i][start]) // 우측으로 이동 가능한 경우
                start++;
            else if (start - 1 >= 1 && check[i][start - 1]) // 좌측으로 이동 가능한 경우
                start--;
        }
        // 시작 세로선과 동일하지 않다면 실패
        if (start != j)
            return false;
    }
    return true;
}

void dfs(int x, int y, int cnt, int limit) // 새로 놓은 사다리, 제한 개수
{
    if (cnt == limit)
    {
        if (isAnswer())
            ans = min(ans, cnt);
        return;
    }
    for (int i = x; i <= H; i++, y = 1)
    {
        for (int j = y; j <= N; j++)
        {
            if (check[i][j - 1] || check[i][j + 1] || check[i][j])
                continue;
            check[i][j] = true;
            dfs(i, j, cnt + 1, limit); // 중복 탐색을 피하기 위해 직전에 사다리를 놓았던 좌표를 전달
            check[i][j] = false;
        }
    }
}

void solve(void)
{
    for (int i = 0; i <= 3; i++)
    {
        dfs(1, 1, 0, i);
    }
    ans == INF ? cout << -1 << "\n" : cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
