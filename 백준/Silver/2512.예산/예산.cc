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
int arr[10000];

 int budget(int mid) {
     int sum = 0;
     for (int i = 0; i < N; i++) {
         if (mid - arr[i] >= 0)
             sum += arr[i];
         else
             sum += mid;
     }
     return sum;
 }

 int binary_search(int left, int right) {
     int ans = 0;
     while (left <= right) {
         int mid = (left + right) / 2;
         int sum = budget(mid);
         if (sum > M)
             right = mid - 1;
         else {
             ans = max(ans, mid);
             left = mid + 1;
         }
     }
     return ans;
 }

int main(void) {
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + N);
    cin >> M;
    if (sum <= M)
        cout << arr[N - 1];
    else
        cout << binary_search(1, M);
    return 0;
}