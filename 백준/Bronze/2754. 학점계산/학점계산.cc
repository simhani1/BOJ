#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

string str;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    if (str == "A+")
        cout << "4.3";
    else if (str == "A0")
        cout << "4.0";
    else if (str == "A-")
        cout << "3.7";
    else if (str == "B+")
        cout << "3.3";
    else if (str == "B0")
        cout << "3.0";
    else if (str == "B-")
        cout << "2.7";
    else if (str == "C+")
        cout << "2.3";
    else if (str == "C0")
        cout << "2.0";
    else if (str == "C-")
        cout << "1.7";
    else if (str == "D+")
        cout << "1.3";
    else if (str == "D0")
        cout << "1.0";
    else if (str == "D-")
        cout << "0.7";
    else if (str == "F")
        cout << "0.0";
    return 0;
}