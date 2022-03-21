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

vector <pair<int,int>> v;
//자료형, 구현체, 비교 연산자 (greater: 오름차순, less: 내림차순)
priority_queue <int, vector<int>, greater<int>> pq;
int N, S, T;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S >> T;
        v.push_back({ S,T });
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        pq.push(v[i].second);
        if (pq.top() <= v[i].first) {
            pq.pop();
        }
    }
    cout << pq.size();
    return 0;
}