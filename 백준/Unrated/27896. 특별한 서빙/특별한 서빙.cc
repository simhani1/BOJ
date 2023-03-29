#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;
#define INF 123456789
typedef long long ll;

int N, M, sum = 0, cnt = 0;
priority_queue<int> pq;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        sum += X;
        pq.push(X);
        if (sum >= M)
        {
            sum -= (pq.top() * 2);
            pq.pop();
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
