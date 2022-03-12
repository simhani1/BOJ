#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <map>

using namespace std;
typedef long long ll;

queue <pair<ll, int>> q;
map <int, bool> visited;
ll ans = 0;

void bfs(ll start, ll goal) {
    bool flag = false;
    q.push({ start, 0 });
    visited[start] = true;
    while (!q.empty()) {
        ll now = q.front().first;
        ll cnt = q.front().second;
        q.pop();
        if (now == goal) {
            ans = cnt + 1;
            break;
        }
        if (now * 2 <= goal && !visited[now * 2]) {
            visited[now * 2] = true;
            q.push({ now * 2, cnt + 1 });
        }
        if (now * 10 + 1 <= goal && !visited[now * 10 + 1]) {
            visited[now * 10 + 1] = true;
            q.push({ now * 10 + 1,cnt + 1 });
        }
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int A, B;
    cin >> A >> B;
    bfs(A, B);
    if (ans == 0)
        cout << -1;
    else
        cout << ans;
    return 0;
}