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
#define MAX 98765432198765
typedef long long ll;

int N, H, K;
ll arr[500002];

void imos(void)
{
    for (int i = 0; i < N; i++)
    {
        cin >> K;
        if (i % 2 == 0)
        {
            arr[0]++;
            arr[K]--;
        }
        else
        {
            arr[H - K]++;
            arr[H]--;
        }
    }
    for (int i = 1; i <= H; i++)
    {
        arr[i] += arr[i - 1];
    }
    sort(arr, arr + H);
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> H;
    imos();
    ll ans = arr[0], cnt = 0;
    for (int i = 0; i < H; i++)
    {
        if (arr[i] == ans)
            cnt++;
    }
    cout << ans << " " << cnt << "\n";
    return 0;
}
