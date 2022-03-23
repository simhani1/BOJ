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
    int N, W;
    vector <int> v;
    vector <int> ans;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> W;
        v.push_back(W);
    }
    sort(v.begin(), v.end());
    int result = 0;
    for (int i = 0; i < N; i++) {
        int std = v[i];
        int cnt = N - i;
        result = max(result, std * cnt);
    }
    cout << result;
    return 0;
}