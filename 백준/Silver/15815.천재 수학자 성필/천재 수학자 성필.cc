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
    char c;
    int num1, num2;
    while (c = cin.get()) {
        if (c == '\n')
            break;
        if (48 <= c && c <= 57)
            st.push(c - 48);
        //*
        else {
            num2 = st.top();
            st.pop();
            num1 = st.top();
            st.pop();
            // *
            if (c == 42)
                st.push(num1 * num2);
            // +
            else if (c == 43)
                st.push(num1 + num2);
            // -
            else if (c == 45)
                st.push(num1 - num2);
            // /
            else if (c == 47)
                st.push(num1 / num2);
        }
    }
    cout << st.top();
    return 0;
}