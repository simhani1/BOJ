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

int s1, s2, s3;
int arr[81];
int len, height, width;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> len >> height >> width;
    cout << (int)(len / sqrt(height * height + width * width) * height) << " " << (int)(len / sqrt(height * height + width * width) * width);
    return 0;
}
