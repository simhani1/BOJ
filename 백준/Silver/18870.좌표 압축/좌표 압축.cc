#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector <int> v;
vector <int> ans;

int main(void) {
	int N, n;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n);
		v.push_back(n);
		ans.push_back(n);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < N; i++) {
		// lower_bound: ans[i]이상의 숫자가 처음 나오는 위치의 인덱스 번호를 반환
		printf("%d ", lower_bound(v.begin(), v.end(), ans[i]) - v.begin());
	}
	return 0;
}