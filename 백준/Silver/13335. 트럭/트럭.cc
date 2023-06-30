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
#define INF 1234567890
typedef long long ll;

int N, W, L;
int arr[1001];
queue<int> q;

void input(void)
{
    cin >> N >> W >> L;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

void solve(void)
{
    int sum = 0, t = 0;
    for (int i = 0; i < N; i++)
    {
        while (true)
        {
            if (q.size() == W)
            {
                sum -= q.front();
                q.pop();
            }
            if (sum + arr[i] <= L)
                break;
            q.push(0);
            t++;
        }
        q.push(arr[i]);
        sum += arr[i];
        t++;
    }
    t += W;
    cout << t << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
