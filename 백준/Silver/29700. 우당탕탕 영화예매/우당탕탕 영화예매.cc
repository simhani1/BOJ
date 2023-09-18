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
#define INF 1e9
#define MOD 1000000
typedef long long ll;

int N, M, K;
int arr[1001][5001];

void input()
{
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = str[j] - '0';
        }
    }
}

void solve(void)
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int cnt = 0;
            for (int idx = j; idx < j + K; idx++)
            {
                if (0 <= idx && idx < M && !arr[i][idx])
                    cnt++;
            }
            if (cnt == K)
                ans++;
        }
    }
    cout << ans << "\n";
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
