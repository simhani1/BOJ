#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define INF 1234567890
typedef long long ll;

int N, maxHeight = 0;
int arr[1000001];
vector<int> arrow;

void input(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
}

void solve(void)
{
    for (int i = 0; i < N; i++)
    {
        bool flag = false;
        for (int j = 0; j < arrow.size(); j++)
        {
            if (arr[i] == arrow[j] - 1)
            {
                arrow[j]--;
                flag = true;
                break;
            }
        }
        if (!flag)
            arrow.push_back(arr[i]);
    }
    cout << arrow.size() << "\n";
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    solve();
    return 0;
}
