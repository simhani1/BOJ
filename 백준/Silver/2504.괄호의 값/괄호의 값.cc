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
    stack <char> s;
    string str;
    cin >> str;
    int tmp = 1, ans = 0;
    int i = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            tmp *= 2;
            s.push('(');
        }
        else if (str[i] == '[') {
            tmp *= 3;
            s.push('[');
        }
        else if (str[i] == ')') {
            if (s.empty() || s.top() != '(') {
                ans = 0;
                break;
            }
            if (str[i - 1] == '(') {
                ans += tmp;
                tmp /= 2;
                s.pop();
            }
            else {
                tmp /= 2;
                s.pop();
            }
        }
        else if (str[i] == ']') {
            if (s.empty() || s.top() != '[') {
                ans = 0;
                break;
            }
            if (str[i - 1] == '[') {
                ans += tmp;
                tmp /= 3;
                s.pop();
            }
            else {
                tmp /= 3;
                s.pop();
            }
        }
    }
    if (!s.empty())
        ans = 0;
    cout << ans;
    return 0;
}