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

int S;
string str;

void draw(void)
{
    for (int i = 0; i < 2 * S + 3; i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            for (int k = 0; k < S + 2; k++)
            {
                if (i == 0)
                {
                    if (k == 0)
                        cout << " ";
                    else if (k == S + 1)
                        cout << " ";
                    else
                    {
                        if (str[j] == '1' || str[j] == '4')
                            cout << " ";
                        else
                            cout << "-";
                    }
                }
                else if (0 < i && i < S + 1)
                {
                    // 1 2 3 7 -> 오른쪽만
                    // 5 6 -> 왼쪽만
                    // 4 8 9 0 -> 양쪽
                    if (str[j] == '1' || str[j] == '2' || str[j] == '3' || str[j] == '7')
                    {
                        if (k == S + 1)
                        {
                            cout << "|";
                        }
                        else
                            cout << " ";
                    }
                    else if (str[j] == '5' || str[j] == '6')
                    {
                        if (k == 0)
                        {
                            cout << "|";
                        }
                        else
                            cout << " ";
                    }
                    else
                    {
                        if (k == 0 || k == S + 1)
                            cout << "|";
                        else
                            cout << " ";
                    }
                }
                else if (i == S + 1)
                {
                    if (k == 0)
                        cout << " ";
                    else if (k == S + 1)
                        cout << " ";
                    else
                    {
                        if (str[j] == '1' || str[j] == '7' || str[j] == '0')
                            cout << " ";
                        else
                            cout << "-";
                    }
                }
                else if (S + 1 < i && i < 2 * S + 2)
                {
                    // 1 3 4 5 7 9 -> 오른쪽
                    // 2 -> 왼쪽
                    // 나머지 -> 양쪽
                    if (str[j] == '1' || str[j] == '3' || str[j] == '4' || str[j] == '5' || str[j] == '7' || str[j] == '9')
                    {
                        if (k == S + 1)
                        {
                            cout << "|";
                        }
                        else
                            cout << " ";
                    }
                    else if (str[j] == '2')
                    {
                        if (k == 0)
                        {
                            cout << "|";
                        }
                        else
                            cout << " ";
                    }
                    else
                    {
                        if (k == 0 || k == S + 1)
                            cout << "|";
                        else
                            cout << " ";
                    }
                }
                else
                {
                    if (k == 0)
                        cout << " ";
                    else if (k == S + 1)
                        cout << " ";
                    else
                    {
                        if (str[j] == '1' || str[j] == '4' || str[j] == '7')
                            cout << " ";
                        else
                            cout << "-";
                    }
                }
            }
            cout << " ";
        }
        cout << "\n";
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> S >> str;
    draw();
    return 0;
}