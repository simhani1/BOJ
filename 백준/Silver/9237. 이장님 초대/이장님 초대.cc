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
    int time[100000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> time[i];
    }
    //내림차순 정렬
    sort(time, time + N, greater<int>());
    //나무가 다 자라나는 날을 저장
    int cnt = 2;  //2일차 부터 첫 나무가 자라기 시작
    for (int i = 0; i < N; i++) {
        time[i] += cnt;
        cnt++;
    }
    sort(time, time + N, greater<int>());
    cout << time[0];
    return 0;
}