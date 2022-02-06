#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int T;
stack<char> vps;
string s;

int main() {
    scanf("%d", &T); 
    for (int i = 0; i < T; i++) {
        cin >> s;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || vps.empty()) {  
                vps.push(s[i]);  
            }
            else if (vps.top() == '(' && s[i] == ')') {
                vps.pop();
            }
        }
        if (vps.empty())
            printf("YES\n");
        else 
            printf("NO\n");
        while (!vps.empty()) { 
            vps.pop();
        }
    }
    return 0;
}