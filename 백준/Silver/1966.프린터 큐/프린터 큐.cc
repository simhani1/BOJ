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

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int T, N, M, n;
    cin >> T;
    for (int i = 0; i < T;i++) {
        queue <pair <int, int>> q;
        priority_queue <int> pq;
        int cnt = 0;
        cin >> N >> M;
        for (int j = 0; j < N; j++) {
            cin >> n;
            q.push({ j,n });  //문서의 인덱스와 우선순위를 저장
            pq.push(n);
        }
        while (!q.empty()) {
            int idx = q.front().first;
            int impo = q.front().second;
            if (pq.top() == impo) {
                pq.pop();
                q.pop();
                cnt++;
                if (M == idx) {
                    cout << cnt << endl;
                    break;
                }
            }
            else {
                q.push(q.front());
                q.pop();
            }
        }
    }
    return 0;
}