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
char name[40];
int arr[27];
bool flag;

int main(void)
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> name;
        arr[name[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] >= 5)
        {
            printf("%c", i + 'a');
            flag = true;
        }
    }
    if (!flag)
        cout << "PREDAJA";
    return 0;
}
