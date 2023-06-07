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

int N;
vector<int> v;

void solve(void)
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int sum = v[i];
        int cnt = 1;
        for (int j = i + 1; j < N; j++)
        {
            if (sum < v[j])
                continue;
            sum += v[j];
            cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans << "\n";
}

void input(void)
{
    cin >> N;
    for (int i = 0, A; i < N; i++)
    {
        cin >> A;
        v.push_back(A);
    }
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
