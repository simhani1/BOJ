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

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    int start_time, end_time;
    vector <pair<int, int>> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> start_time >> end_time;
        v.push_back({ end_time, start_time });
    }
    //종료시간 기준 정렬
    //빨리 끝날수록 많은 수업 가능
    sort(v.begin(), v.end());
    int last_class = v[0].first;
    //회의 한개는 무조건 진행 가능
    int cnt = 1;
    for (int i = 1; i < N; i++) {
        if (last_class <= v[i].second) {
            last_class = v[i].first;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}