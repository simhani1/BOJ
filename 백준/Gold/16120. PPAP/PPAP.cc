#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <map>
#include <set>
using namespace std;
#define INF 123456789
#define MAX 2000000000
typedef long long ll;

int cnt = 0; // 연속한 p의 개수
string str;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'P')
        {
            cnt++;
            continue;
        }
        if (cnt >= 2 && str[i + 1] == 'P')
        {
            cnt--;
            i++;
        }
        else
        {
            cout << "NP\n";
            return 0;
        }
    }
    if (cnt == 1)
        cout << "PPAP\n";
    else
        cout << "NP\n";
    return 0;
}
