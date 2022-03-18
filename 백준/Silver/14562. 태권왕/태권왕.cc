#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <map>

using namespace std;

void bfs(int s, int c, int cnt) {
    queue <pair<pair<int, int>, int>> q;
    q.push({ {s,c},cnt });
    while (!q.empty()) {
        int now_s = q.front().first.first;
        int now_t = q.front().first.second;
        int now_cnt = q.front().second;
        q.pop();
        if (now_s > now_t)
            continue;
        else if (now_s == now_t) {
            cout << now_cnt << endl;
            break;
        }
        q.push({ {now_s * 2, now_t + 3}, now_cnt + 1 });
        q.push({ {now_s + 1, now_t}, now_cnt + 1 });
    }
}

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int C, S, T;
    cin >> C;
    while (C--) {
        cin >> S >> T;
        bfs(S, T, 0);
    }
    return 0;
}