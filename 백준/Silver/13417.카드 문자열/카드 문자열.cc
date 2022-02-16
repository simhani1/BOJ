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
    int T, N;
    char s;
    deque <char> deq;
    queue <char> q;
    cin >> T;
    while(T--) {
        cin >> N;
        while (N--) {
            cin >> s;
            q.push(s);
        }
        while (!q.empty()) {
            if (deq.empty()) {
                deq.push_front(q.front());
                q.pop();
            }
            else if (deq.front() < q.front()) {
                deq.push_back(q.front());
                q.pop();
            }
            else if (deq.front() >= q.front()) {
                deq.push_front(q.front());
                q.pop();
            }
        }
        while (!deq.empty()) {
            cout << deq.front();
            deq.pop_front();
        }
        cout << endl;
    }
    return 0;
}