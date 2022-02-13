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
int  arr[5005];
bool flag = false;

int main(void) {
    scanf("%d %d", &N, &C);
    for (int i = 1; i <= N; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr + 1, arr + 1 + N);
    int left = 1, right = N;
    //물건 한개의 무게와 같을 경우
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == C) {
            flag = true;
            break;
        }
        if (arr[mid] < C)
            left = mid + 1;
        else
            right = mid - 1;
    }
    if (!flag) {
        left = 1, right = N;
        //물건 두개의 무게와 같을 경우
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == C) {
                flag = true;
                break;
            }
            if (sum > C)
                right -= 1;
            //물건 세개의 무게와 같을 경우
            else {
                int left_new = 1, right_new = N;
                int diff = C - sum;
                while (left_new <= right_new) {
                    int mid = (left_new + right_new) / 2;
                    if (diff == arr[mid]) {
                        //두개 합을 구하면서 이미 선택된 물건인지 판별
                        if (mid != left && mid != right)
                            flag = true;
                        break;
                    }
                    if (diff < arr[mid])
                        right_new = mid - 1;
                    else
                        left_new = mid + 1;
                }
                if (flag)
                    break;
                else
                    left += 1;
            }
        }
    }
    if (flag)
        printf("%d", 1);
    else
        printf("%d", 0);
    return 0;
}