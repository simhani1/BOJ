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

int N, K;
int arr[1000010], pSum[1000010];
pair<int, int> ans;

void input(void)
{
    cin >> N >> K;
    for (int i = 0, X, Y; i < N; i++)
    {
        cin >> X >> Y;
        for (int j = X + 1; j <= Y; j++)
        {
            arr[j]++;
        }
    }
    for (int i = 1; i <= 1000000; i++)
    {
        pSum[i] = pSum[i - 1] + arr[i];
        //        cout<< "i: "<<i << " "<<pSum[i]<<endl;
    }
}

void solve(void)
{
    int l = 0, r = 1;
    while (l <= r && r <= 1000000)
    {
        int tmp = pSum[r] - pSum[l];
        if (tmp < K)
            r++;
        else if (tmp > K)
            l++;
        else
        {
            ans = {l, r};
            break;
        }
    }
    cout << ans.first << " " << ans.second << "\n";
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
