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

deque <int> deq;
vector <int> v;
int N, K, M;
bool flag = false;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> K >> M;
    for (int i = 1; i <= N; i++) {
        deq.push_back(i);
    }
    int cnt = 0;
    while (deq.size()) {
        if (flag == false) {
            for (int i = 0; i < K - 1; i++) {
                deq.push_back(deq.front());
                deq.pop_front();
            }
            v.push_back(deq.front());
            deq.pop_front();
            cnt++;
        }
        else {
            for (int i = 0; i < K - 1; i++) {
                deq.push_front(deq.back());
                deq.pop_back();
            }
            v.push_back(deq.back());
            deq.pop_back();     
            cnt++;
        }
        if (cnt == M) {
            if (flag)
                flag = false;           
            else
                flag = true;
            cnt = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << v[i] << '\n';
    }
    return 0;
}
