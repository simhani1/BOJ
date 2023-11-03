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

int N;
vector<int> v;

void input(void)
{
    cin >> N;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        v.push_back(X);
    }
}

void solve(void)
{
    sort(v.begin(), v.end());
    int ans = INF;
    for (int i = 0; i < N - 3; i++)
    {
        for (int j = i + 3; j < N; j++)
        {
            int A = v[i] + v[j];
            int l = i + 1, r = j - 1;
            while (l < r)
            {
                int B = v[l] + v[r];
                ans = min(ans, abs(A - B));
                if (A > B)
                    l++;
                else if (A < B)
                    r--;
                else
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
