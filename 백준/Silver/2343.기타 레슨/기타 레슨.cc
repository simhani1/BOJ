#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <time.h>

using namespace std;

int N, M;
int arr[100000];

int count(int m) {
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
        if (m < sum) {
            sum = 0;
            cnt++;
            i--;
        }
    }
    return cnt;
}

int main(void) {
    scanf("%d %d", &N, &M);
    int right = 0;
    int left = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
        right += arr[i];
        left = max(left, arr[i]);
    }
    while (left <= right) {
        int mid = (left + right) / 2;
        if (count(mid) <= M)
            right = mid - 1;
        else
            left = mid + 1;
    }
    printf("%d\n", left);
    return 0;
}