#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
#define INF 2147483648
typedef long long ll;

int T, H, W, N;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> H >> W >> N;
        int ans;
        if (N % H)
            ans = 100 * (N % H) + (N / H) + 1;
        else
            ans = 100 * H + (N / H);
        cout << ans << endl;
    }
    return 0;
}
