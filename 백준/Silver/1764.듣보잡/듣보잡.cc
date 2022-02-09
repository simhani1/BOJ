#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int N, M;
string str;
vector <string> v1;
vector <string> v2;

int main(void) {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v1.push_back(str);
	}
	sort(v1.begin(), v1.end());
	int cnt = 0;
	for (int i = 0; i < M; i++) {
		cin >> str;
		if (binary_search(v1.begin(), v1.end(), str)) {  //문자열이 있을 경우 true 반환
			v2.push_back(str);
			cnt++;
		}
	}
	cout << cnt << endl;
	sort(v2.begin(), v2.end());
	for (int i = 0; i < cnt; i++) {
		cout << v2[i] << endl;
	}
	return 0;
}

