#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX_N 250001
#define MAX_T 1000001
#define LL long long
#define INF 1e9

using namespace std;
int N, K;
int MAP[MAX_N];
int SegTree[MAX_T];
LL answer = 0;

void Input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> MAP[i];
	}
}

void Update_SegTree(int Node, int S, int E, int Val, int Diff) {
	if (S == E) {
		SegTree[Node] += Diff;
		return;
	}
	int M = (S + E) / 2;
	if (Val <= M) {
		Update_SegTree(Node * 2, S, M, Val, Diff);
	}
	else {
		Update_SegTree(Node * 2 + 1, M + 1, E, Val, Diff);
	}
	SegTree[Node] = SegTree[Node * 2] + SegTree[Node * 2 + 1];
}

int Find_Value(int Node, int S, int E, int Val) {
	if (S == E) {
		return S;
	}
	int M = (S + E) / 2;
	if (Val <= SegTree[Node * 2]) {
		return Find_Value(Node * 2, S, M, Val);
	}
	else {
		return Find_Value(Node * 2 + 1, M + 1, E, Val - SegTree[Node * 2]);
	}
}

void Settings() {
	for (int i = 0; i < (K - 1); i++) {
		Update_SegTree(1, 0, 65535, MAP[i], 1);
	}
}

void Find_Answer() {
	for (int i = (K - 1); i < N; i++) {
		Update_SegTree(1, 0, 65535, MAP[i], 1);
		answer += Find_Value(1, 0, 65535, (K + 1) / 2);
		Update_SegTree(1, 0, 65535, MAP[i - K + 1], -1);
	}
	cout << answer << "\n";
}

int main() {
	FASTIO
	Input();
	Settings();
	Find_Answer();

	return 0;
}