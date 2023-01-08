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
#define INF 987654321
#define INIT 100000000
typedef long long ll;

int T, N;
vector<pair<int, int>> v;

int solve(void)
{
    int std = v[0].second;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (v[i].second <= std)
        {
            std = v[i].second;
            ans++;
        }
    }
    return ans;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0, A, B; i < N; i++)
        {
            cin >> A >> B;
            v.push_back({A, B});
        }
        sort(v.begin(), v.end());
        cout << solve() << "\n";
        v.clear();
    }
    return 0;
}
