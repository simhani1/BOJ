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
#define MAX 987654321
typedef long long ll;

int N, M;
bool dp[2001][2001];
int arr[2001];

void solve(void) {
    for (int i = 0; i < N; i++) {
        if (arr[i] == arr[i + 1])
            dp[i][i + 1] = true;
        else
            dp[i][i + 1] = false;
    }
    for (int i = N - 2; i >= 0; i--) {
        for (int j = i + 2; j < N; j++) {
            if (arr[i] == arr[j]) {
                if (dp[i + 1][j - 1])
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
            else
                dp[i][j] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i][i] = true;
    }
    solve();
    cin >> M;
    for (int i = 0, A, B; i < M; i++) {
        cin >> A >> B;
        A = min(A, B);
        B = max(A, B);
        if (dp[A - 1][B - 1])
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    return 0;
}
