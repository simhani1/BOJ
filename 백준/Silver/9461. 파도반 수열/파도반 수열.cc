#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll arr[100] = { 1,1,1,2,2 };

ll padovan(int n) {
	if (n < 6) {
		return arr[n - 1];
	}
	else {
		for (int i = 6; i <= n; i++) {
			arr[i - 1] = arr[i - 2] + arr[i - 6];
		}
		return arr[n - 1];
	}
}

int main(void) {
	int T, N;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%lld\n", padovan(N));
	}
	return 0;
}