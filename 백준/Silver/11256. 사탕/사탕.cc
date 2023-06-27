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

int T, J, N;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        priority_queue<int> pq;
        int cnt = 0;
        cin >> J >> N;
        for (int i = 0, R, C; i < N; i++)
        {
            cin >> R >> C;
            pq.push(R * C);
        }
        while (!pq.empty())
        {
            int nowSize = pq.top();
            pq.pop();
            if (J <= 0)
                break;
            J -= nowSize;
            cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}
