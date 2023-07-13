#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	vector <int> A;
	vector <int> B;
	int i, size_A, size_B, n;

	scanf("%d", &size_A);
	scanf("%d", &size_B);

	for (i = 0; i < size_A; i++) {  //A벡터에 데이터 삽입
		scanf("%d", &n);
		A.push_back(n);
	}
	for (i = 0; i < size_B; i++) {  //B벡터에 데이터 삽입
		scanf("%d", &n);
		B.push_back(n);
	}

	for (i = 0; i < B.size(); i++) {  //B벡터의 데이터들을 A벡터에 삽입
		A.push_back(B[i]);
	}

	sort(A.begin(), A.end());  //오름차순 정렬

	for (i = 0; i < A.size(); i++) {  //A벡터 데이터 출력
		printf("%d ", A[i]);
	}
	return 0;
}