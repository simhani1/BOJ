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
#define MAX 987654321
typedef long long ll;

string str;
int cntP = 0, cntK = 0;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'K')
        {
            cntK++;
            if (cntP)
                cntP--;
        }
        else
        {
            cntP++;
            if (cntK)
                cntK--;
        }
    }
    cout << cntP + cntK << "\n";
    return 0;
}
