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

string mbti;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> mbti;
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            if (mbti[i] == 'E')
                cout << 'I';
            else if (mbti[i] == 'I')
                cout << 'E';
        }
        else if (i == 1)
        {
            if (mbti[i] == 'N')
                cout << 'S';
            else if (mbti[i] == 'S')
                cout << 'N';
        }
        else if (i == 2)
        {
            if (mbti[i] == 'F')
                cout << 'T';
            else if (mbti[i] == 'T')
                cout << 'F';
        }
        else if (i == 3)
        {
            if (mbti[i] == 'P')
                cout << 'J';
            else if (mbti[i] == 'J')
                cout << 'P';
        }
    }
    return 0;
}