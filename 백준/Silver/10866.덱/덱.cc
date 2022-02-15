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
    deque <int> deq;
    int N, n;
    string s;
    cin >> N;
    while (N--) {
        cin >> s;
        if (s == "push_front") {
            cin >> n;
            deq.push_front(n);
        }
        else if (s == "push_back") {
            cin >> n;
            deq.push_back(n);
        }
        else if (s == "pop_front") {
            if (deq.empty())
                cout << -1 << '\n';
            else {
                cout << deq.front() << '\n';
                deq.pop_front();
            }
        }
        else if (s == "pop_back") {
            if (deq.empty())
                cout << -1 << '\n';
            else {
                cout << deq.back() << '\n';
                deq.pop_back();
            }
        }
        else if (s == "size")
            cout << deq.size() << '\n';
        else if (s == "empty")
            cout << deq.empty() << '\n';
        else if (s == "front") {
            if (deq.empty())
                cout << -1 << '\n';
            else
                cout << deq.front() << '\n';
        }
        else if (s == "back") {
            if (deq.empty())
                cout << -1 << '\n';
            else
                cout << deq.back() << '\n';
        }
    }
    return 0;
}