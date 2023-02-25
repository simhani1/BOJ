#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define INF 2147483648
typedef long long ll;

int N, ans = 0;
int arr[9];
bool visited[9];
vector<int> v;

void dfs(int idx)
{
    if (idx == N)
    {
        int tmp = 0;
        for (int i = 0; i < v.size() - 1; i++)
            tmp += abs(v[i] - v[i + 1]);
        ans = max(ans, tmp);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if (!visited[i])
        {
            v.push_back(arr[i]);
            visited[i] = true;
            dfs(idx + 1);
            v.pop_back();
            visited[i] = false;
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    dfs(0);
    cout << ans << "\n";
    return 0;
}
