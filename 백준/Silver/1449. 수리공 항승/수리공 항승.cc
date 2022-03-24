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
    int N, L;
    vector <int> v;
    cin >> N >> L;
    v.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int start = 1, end = 1;
    //테이프 한개는 무조건 사용
    int cnt = 1;
    while (1) {
        if (end == N + 1) {
            break;
        }
        //인접한 두 지점 사이의 거리가 L-1까지만 테이프 하나로 커버 가능
        if (v[end] - v[start] <= L - 1) {
            end++;
        }
        //한계 범위를 넘어갈 경우 테이프의 개수 증가 및 start 인덱스 수정
        else {
            cnt++;
            start = end;
        }
    }
    cout << cnt;
    return 0;
}