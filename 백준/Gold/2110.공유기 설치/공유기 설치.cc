#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <time.h>

using namespace std;

int N, C;
int arr[200000];

int count(int mid, int std) {
    int cnt = 1;
    for (int i = 0; i < N; i++) {
        if (mid <= arr[i] - std) {
            std = arr[i];
            cnt++;
        }
    }
    return cnt;
}

int binary_search(int left, int right) {
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;  //공유기 사이의 거리
        int cnt = count(mid, arr[0]);
        if (cnt < C)  //설치 가능한 공유기 수가 적으므로 설치 간격을 줄여야 함
            right = mid - 1;
        else {  //설치 가능한 공유기 수가 많거나 같으므로 설치 간격을 증가시켜야 함
            ans = mid;  //설치 가능한 공유기 수가 같으면서 거리가 다른 경우가 있을 수 있음
            left = mid + 1;
        }
    }
    return ans;
}   

int main(void) {
    scanf("%d %d", &N, &C);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + N);
    printf("%d", binary_search(1, arr[N - 1] - arr[0]));
    return 0;
}
