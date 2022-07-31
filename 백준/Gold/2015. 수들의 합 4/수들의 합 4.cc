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
typedef long long ll;

int N, K, A;
ll sum[200001];
map<int, ll> psum;
ll ans = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    // 부분합 저장
    for (int i = 1; i <= N; i++)
    {
        cin >> A;
        sum[i] = sum[i - 1] + A;
        // i번째 까지의 부분합이 K일 경우
        if (sum[i] == K)
            ans++;
    }
    // K가 되는 부분합의 개수 저장
    // "sum[3] - sum[1] == K" === "sum[3] - K == sum[1]"
    // 즉 sum[i] - K == P 라면 다른 케이스 중 결과가 P가 되는 개수가 부분합 중 K와 동일한 결과의 개수
    for (int i = 1; i <= N; i++)
    {
        ans += psum[sum[i] - K];
        psum[sum[i]] += 1;
    }
    cout << ans;
    return 0;
}
