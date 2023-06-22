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

int N, M;
int arr[100001], pSum[100001];

void input(void)
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    pSum[1] = arr[1];
    for (int i = 2; i <= N; i++)
    {
        pSum[i] += (pSum[i - 1] + arr[i]);
    }
}

void solve(void)
{
    int A, B;
    while (M--)
    {
        cin >> A >> B;
        cout << pSum[B] - pSum[A - 1] << "\n";
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
