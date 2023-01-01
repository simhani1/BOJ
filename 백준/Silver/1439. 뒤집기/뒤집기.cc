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
#define MAX 98765432198765
typedef long long ll;

string str;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    int cntZeros = 0, cntOnes = 0;
    char tmp = str[0];
    for (int i = 0; i < str.length(); i++)
    {
        if (tmp != str[i])
        {
            if (tmp == '0')
                cntZeros++;
            else
                cntOnes++;
        }
        tmp = str[i];
        if (i == str.length() - 1)
        {
            if (str[i] == '0')
                cntZeros++;
            else
                cntOnes++;
        }
    }
    cout << min(cntZeros, cntOnes) << "\n";
    return 0;
}
