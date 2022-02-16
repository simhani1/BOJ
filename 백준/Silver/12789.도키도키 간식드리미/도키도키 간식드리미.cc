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
    int N, n;
    stack <int> s;
    queue <int> q;
    int std = 1;
    cin >> N;
    while (N--) {
        cin >> n;
        q.push(n);  
    }
    while (!q.empty()) {
        if (q.front() == std) {
            q.pop();
            std++;
        }
        else if (!s.empty() && s.top() == std) {
            s.pop();
            std++;
        }
        else {
            s.push(q.front());
            q.pop();
        }
    }
    while (!s.empty()) {
        if (s.top() == std) {
            s.pop();
            std++;
        }
        else
            break;
    }
    if (s.empty())
        cout << "Nice";
    else
        cout << "Sad";
    return 0;
}