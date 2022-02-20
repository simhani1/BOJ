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
    int N;
    priority_queue <int, vector<int>, greater<int>> pq;
    cin >> N;
    while (N--) {
        int n;
        cin >> n;
        if (n == 0) {
            if (pq.empty()) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(n);
        }
    }
    return 0;
}