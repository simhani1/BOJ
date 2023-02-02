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
#define INF 2147483648
typedef long long ll;

string str;
int A, B;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    for (int i = 1; i < 1000; i++)
    {
        string tmp;
        A = i;
        for (int j = i; j < 1000; j++)
        {
            tmp += to_string(j);
            if (tmp == str)
            {
                B = j;
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    return 0;
}
