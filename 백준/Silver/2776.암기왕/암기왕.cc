#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int N, M;
int num1[1000000];
int num2[1000000];

int binary_search(int left, int right, int find) {
    int mid = (left + right) / 2;
    if (left > right)
        return 0;
    if (num1[mid] == find)
        return 1;
    else if (num1[mid] < find)
        return binary_search(mid + 1, right, find);
    else
        return binary_search(left, mid - 1, find);
}

int main(void) {
    int T;
    scanf("%d", &T);  //테스트 케이스 수
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            scanf("%d", &num1[j]);
        }
        sort(num1, num1 + N);
        scanf("%d", &M);
        for (int j = 0; j < M; j++) {
            scanf("%d", &num2[j]);
            printf("%d\n", binary_search(0, N - 1, num2[j]));
        }
    }
    return 0;
}