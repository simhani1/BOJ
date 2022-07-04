#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector <vector <int>> v;
vector <int> v2;
int cnt_w = 0, cnt_b = 0;

void check_color(int start_row, int start_col, int size) {
	int check = v[start_row][start_col];
	for (int i = start_row; i < start_row + size; i++) {
		for (int j = start_col; j < start_col + size; j++) {
			if (v[i][j] != check) {
				check_color(start_row, start_col, size / 2);
				check_color(start_row, start_col + (size / 2), size / 2);
				check_color(start_row + (size / 2), start_col, size / 2);
				check_color(start_row + (size / 2), start_col + (size / 2), size / 2);
				return;
			}
		}
	}
	if (check == 1)
		cnt_b++;
	else
		cnt_w++;
}

int main(void) {
	int n;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		v.push_back(v2);
		for (int j = 0; j < N; j++) {
			scanf("%d", &n);
			v[i].push_back(n);
		}
	}
	check_color(0, 0, N);
	printf("%d\n%d", cnt_w, cnt_b);
	return 0;
}