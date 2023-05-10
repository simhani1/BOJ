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

int N, T;
vector<int> v, clockwise, antiClockwise;
vector<vector<int>> ans;

void inputSample(void)
{
    cin >> N;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        v.push_back(X);
    }
}

int opositeDirection(int X)
{
    if (X == 1)
        return 3;
    else if (X == 2)
        return 4;
    else if (X == 3)
        return 1;
    else
        return 2;
}

bool checkAnswer(vector<int> vCopy, vector<int> clockWiseCopy, vector<int> antiClockWiseCopy)
{
    int tmp = N;
    while (tmp--)
    {
        if (vCopy == clockWiseCopy || vCopy == antiClockWiseCopy)
            return true;
        else
        {
            clockWiseCopy.push_back(clockWiseCopy.front());
            clockWiseCopy.erase(clockWiseCopy.begin());
            antiClockWiseCopy.push_back(antiClockWiseCopy.front());
            antiClockWiseCopy.erase(antiClockWiseCopy.begin());
        }
    }
    return false;
}

void inputExample(void)
{
    cin >> T;
    while (T--)
    {
        for (int i = 0, X; i < N; i++)
        {
            cin >> X;
            clockwise.push_back(X);
            antiClockwise.push_back(opositeDirection(X));
        }
        reverse(antiClockwise.begin(), antiClockwise.end());
        if (checkAnswer(v, clockwise, antiClockwise))
            ans.push_back(clockwise);
        clockwise.clear();
        antiClockwise.clear();
    }
}

void solve(void)
{
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        for (auto i : ans[i])
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    inputSample();
    inputExample();
    solve();
    return 0;
}
