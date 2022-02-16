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
    int N, P;
    stack <int> s[7];
    int n, p;
    int cnt = 0;
    cin >> N >> P;
    while (N--) {
        cin >> n >> p;
        if (s[n].empty()) {
            s[n].push(p);
            cnt++;
        }
        else {
            if (s[n].top() < p) {
                s[n].push(p);
                cnt++;
            }
            else if (s[n].top() > p) {
                while (!s[n].empty() && s[n].top() > p) {
                    s[n].pop();
                    cnt++;
                }
                if (!s[n].empty() && s[n].top() == p)
                    continue;
                s[n].push(p);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}