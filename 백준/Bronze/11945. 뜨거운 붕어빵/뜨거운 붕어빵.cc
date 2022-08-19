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

int A, B;
string str;
vector<string> v;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B;
    for (int i = 0; i < A; i++)
    {
        cin >> str;
        v.push_back(str);
        reverse(v[i].begin(), v[i].end());
    }
    for (int i = 0; i < A; i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}
