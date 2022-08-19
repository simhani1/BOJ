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

int N;
bool flag;
string str;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    while (N--)
    {
        cin >> str;
        if (str == "anj")
            flag = true;
    }
    if (flag)
        cout << "뭐야;";
    else
        cout << "뭐야?";
    return 0;
}
