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

queue <int> q;
vector <int> v;
int N, K;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        q.push(i);
    }
    int cnt = 0;
    while (q.size()) {
        for (int i = 0; i < K - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        v.push_back(q.front());
        q.pop();
    }
    cout << "<";
    for (int i = 0; i < N; i++) {
        cout << v[i];
        if (i != N - 1)
            cout << ", ";
        else
            cout << ">";
    }
    return 0;
}