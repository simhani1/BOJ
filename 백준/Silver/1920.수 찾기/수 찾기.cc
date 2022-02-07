#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int N, M;
int A[100000];

int binary_search(int left, int right, int ans) {
    int mid = (left + right) / 2;
    if (left > right)
        return 0;
    if (A[mid] == ans)
        return 1;
    else if (A[mid] < ans)
        return binary_search(mid + 1, right, ans);
    else
        return binary_search(left, mid - 1, ans);
}

int main(void) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    sort(A, A + N);
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int n;
        scanf("%d", &n);
        printf("%d\n", binary_search(0, N - 1, n));
    }
    return 0;
}