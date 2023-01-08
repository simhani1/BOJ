#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int N, i, j, d, p;
	int cnt = 0;
	vector <pair <int, int>> v;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d", &d, &p);
		v.push_back({ d,p });
	}
	sort(v.begin(), v.end());
	for (i = 0; i < N; i++) {
		bool flag = false;
		for (j = 0; j < N; j++) {
			if (i != j) {
				if (v[i].first > v[j].first) {  //비교군보다 멀고
					if (v[i].second >= v[j].second) {  //비교군보다 비쌀 경우
						flag = true;
						break;
					}
				}
				else if (v[i].second > v[j].second) {  //비교군보다 비싸고
					if (v[i].first >= v[j].first) {  //비교군보다 멀 경우
						flag = true;
						break;
					}
				}
			}
		}
		if (!flag)
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}