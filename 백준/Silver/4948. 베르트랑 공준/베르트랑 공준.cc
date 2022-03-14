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
#include <map>

using namespace std;

int n;
bool arr[246913];

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    while (1) {
        int cnt = 0;
        cin >> n;
        if (n == 0)
            break;
        int start = n, end = 2 * n;
        //값 저장
        for (int i = 0; i <= end; i++) {
            arr[i] = true;
        }
        for (int i = 2; i <= end; i++) {
            //소수일 경우
            if (arr[i]) {
                //배수들을 모두 false로 처리
                for (int j = i + i; j <= end; j += i) {
                    arr[j] = false;
                }
            }
        }
        for (int i = start + 1; i <= end; i++) {
            //소수일 경우
            if (arr[i])
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}