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
#define MAX 1000001
#define MOD 987654321
typedef long long ll;

int N;
int arr[80001];

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

void solve(void)
{
    stack<int> st;
    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        int now = arr[i];
        if (!st.empty())
        {
            while (st.top() <= now)
            {
                st.pop();
                if (st.empty())
                    break;
            }
            ans += st.size();
        }
        st.push(now);
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
