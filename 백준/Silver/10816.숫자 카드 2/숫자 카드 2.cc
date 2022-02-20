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
    int N, M;
    cin >> N;
    vector <int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cin >> M;
    for (int i = 0; i < M; i++) {        
        int n;
        cin >> n;
        //upper_bound: 찾는 값보다 처음으로 큰 수의 인덱스 반환
        //lower_bound: 찾는 값이 처음으로 나오는 인덱스 반환
        cout << upper_bound(v.begin(), v.end(), n) - lower_bound(v.begin(), v.end(), n) << " ";
    }
    return 0;
}