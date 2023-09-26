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
#define INF 123456789
#define MOD 1000000
typedef long long ll;

int N, K;
char arr[20001];
bool visited[20001];

void input(void)
{
    cin >> N >> K;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        arr[i] = str[i];
    }
}

void solve(void)
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 'H')
            continue;
        for (int j = i - K; j <= i + K; j++)
        {
            if (j < 0 || j >= N || arr[j] == 'P')
                continue;
            if (!visited[j])
            {
                visited[j] = true;
                ans++;
                break;
            }
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
