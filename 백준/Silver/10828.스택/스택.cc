#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <time.h>

using namespace std;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    stack <int> st;
    string s;
    int N, n;
    cin >> N;
    while (N--) {
        cin >> s;
        if (s == "push") {
            cin >> n;
            st.push(n);
        }
        else if (s == "pop") {
            //데이터가 있을 경우
            if (!st.empty()) {
                cout << st.top() << '\n';
                st.pop();
            }
            else
                cout << -1 << '\n';
        }
        else if (s == "top") {
            if (!st.empty())
                cout << st.top() << '\n';
            else
                cout << -1 << '\n';
        }
        else if (s == "size")
            cout << st.size() << '\n';
        else if (s == "empty")
            cout << st.empty() << '\n';
    }
    return 0;
}