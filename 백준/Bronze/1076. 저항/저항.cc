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

string str1, str2, str3;
long long result = 0;

void mul(string s)
{
    if (s == "black")
        result *= 1;
    else if (s == "brown")
        result *= 10;
    else if (s == "red")
        result *= 100;
    else if (s == "orange")
        result *= 1000;
    else if (s == "yellow")
        result *= 10000;
    else if (s == "green")
        result *= 100000;
    else if (s == "blue")
        result *= 1000000;
    else if (s == "violet")
        result *= 10000000;
    else if (s == "grey")
        result *= 100000000;
    else if (s == "white")
        result *= 1000000000;
}

void value(string s)
{
    if (s == "black")
    {
        result *= 10;
        result += 0;
    }
    else if (s == "brown")
    {
        result *= 10;
        result += 1;
    }
    else if (s == "red")
    {
        result *= 10;
        result += 2;
    }
    else if (s == "orange")
    {
        result *= 10;
        result += 3;
    }
    else if (s == "yellow")
    {
        result *= 10;
        result += 4;
    }
    else if (s == "green")
    {
        result *= 10;
        result += 5;
    }
    else if (s == "blue")
    {
        result *= 10;
        result += 6;
    }
    else if (s == "violet")
    {
        result *= 10;
        result += 7;
    }
    else if (s == "grey")
    {
        result *= 10;
        result += 8;
    }
    else if (s == "white")
    {
        result *= 10;
        result += 9;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str1 >> str2 >> str3;
    value(str1);
    value(str2);
    mul(str3);
    cout << result;
    return 0;
}
