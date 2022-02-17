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

stack <char> s;
string str;

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> str;
    int cnt = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(')
            s.push('(');
        else if (str[i] == ')') {
            if (str[i - 1] == '(') {  //레이저
                s.pop();
                cnt += s.size();
            }
            else if (str[i - 1] == ')') {  //막대기
                s.pop();
                cnt += 1;
            }
        }
    }
    cout << cnt;
    return 0;
}