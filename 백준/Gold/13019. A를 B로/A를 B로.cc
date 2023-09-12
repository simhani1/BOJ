#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;
#define INF 1e15
#define MOD 1000000
typedef long long ll;

string from, to;
bool visited[51];

void solve() {
    int ans = 0, idx = to.length() - 1;
    for (int i = from.length() - 1; i >= 0; i--) {
        char f = from[i], t = to[idx];
        if (f != t)
            ans++;
        else
            idx--;
    }
    sort(from.begin(), from.end());
    sort(to.begin(), to.end());
    if (from != to)
        ans = -1;
    cout << ans << "\n";
}

void input() {
    cin >> from >> to;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
