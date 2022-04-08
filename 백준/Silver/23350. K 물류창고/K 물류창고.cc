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
typedef pair<int, int> pii;

int N, M;
int P, W;
vector <int> cnt;
vector<vector<int>> v;
queue <pii> q;

void init(void) {
    cin >> N >> M;
    cnt.resize(M + 1, 0);
    v.resize(M + 1);
    for (int i = 0; i < N; i++) {
        cin >> P >> W;
        q.push({ P,W });
        cnt[P]++;
    }
}

int solve(void) {
    int std = M, ans = 0;
    while (!q.empty()) {
        int nowPriority = q.front().first;
        int nowWeight = q.front().second;
        q.pop();
        if (nowPriority != std) {
            ans += nowWeight;
            q.push({ nowPriority, nowWeight });
        }
        else {
            ans += nowWeight;
            cnt[nowPriority]--;
            if (cnt[nowPriority] == 0)
                std--;
            if (v[nowPriority].empty())
                v[nowPriority].push_back(nowWeight);
            else {
                for (int i = 0; i < v[nowPriority].size(); i++) {
                    //현재 컨테이너의 무게가 적재된 컨테이너 무게보다 가벼울 경우
                    if (v[nowPriority][i] < nowWeight)
                        ans += (2 * v[nowPriority][i]);
                    else
                        break;
                }
                v[nowPriority].push_back(nowWeight);
                sort(v[nowPriority].begin(), v[nowPriority].end());
            }
        }
    }
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    cout << solve();
    return 0;
}