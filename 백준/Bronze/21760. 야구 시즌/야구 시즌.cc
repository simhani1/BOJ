#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	long long t;
	cin >> t;

	while (t--) {
		long double n, m, k, d;
		cin >> n >> m >> k >> d;
		long double t = n * m * (k * (m - 1) + m * (n - 1));
		t = (2 * d) / t;
		long long b = t;
		long long res = (n * m * (m - 1) / 2 * b * k + n * (n - 1) / 2 * m * m * b);
		cout << (res <= 0 ? -1 : res) << '\n';
	}

	return 0;
}
