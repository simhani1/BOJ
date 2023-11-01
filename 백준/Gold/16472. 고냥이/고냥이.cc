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
#define INF 123456789
#define MOD 987654321
typedef long long ll;

int N;
string str;
int visited[30];

void input(void)
{
    cin >> N >> str;
}

void solve(void)
{
    int l = 0, cnt = 1, len = 1; // 문자의 개수, 문자열의 길이
    visited[str[l] - 'a']++;
    for (int r = 1; r < str.length(); r++)
    {
        if (!visited[str[r] - 'a'])
            cnt++;
        visited[str[r] - 'a']++;
        while (cnt > N)
        {
            visited[str[l] - 'a']--;
            if (!visited[str[l] - 'a'])
                cnt--;
            l++;
        }
        len = max(len, r - l + 1);
    }
    cout << len << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
