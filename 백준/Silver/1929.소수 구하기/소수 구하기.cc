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
    int M, N;
    bool visited[1000001] = { 1,1 };
    cin >> M >> N;
    //에라토스테네스의 체
    for (int i = 2; i <= sqrt(N); i++) {
        if (visited[i])
            continue;
        for (int j = i + i; j <= N; j += i) {
            if (visited[j])
                continue;
            visited[j] = true;
        }
    }
    for (int i = M; i <= N; i++) {
        if (!visited[i])
            cout << i << '\n';
    }
    return 0;
}