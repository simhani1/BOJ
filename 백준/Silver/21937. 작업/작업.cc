#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int n, m, x;
bool visit[100005] = { 0, };
vector<int>v[100005];
stack<int>st;

void DFS(int node) {
	visit[node] = 1;
	for (auto next : v[node]) {
		if (visit[next] == 0)
			DFS(next);
	}
	st.push(node);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	while (m--) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}

	cin >> x;

	DFS(x);
	

	cout << st.size() - 1;
}
