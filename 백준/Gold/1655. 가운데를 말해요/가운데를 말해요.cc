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

int N, M;
int arr[100001];
priority_queue<int> maxHeap;                            // 내림차순
priority_queue<int, vector<int>, greater<int>> minHeap; // 오름차순

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        // maxHeap의 크기가 minHeap의 크기보다 1 크거가 같아야 함
        if (maxHeap.size() > minHeap.size())
            minHeap.push(arr[i]);
        else
            maxHeap.push(arr[i]);
        // minHeap의 모든 원소들은 maxHeap의 모든 원소들보다 작거나 같아야 함
        if (!maxHeap.empty() && !minHeap.empty())
        {
            if (maxHeap.top() > minHeap.top())
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        cout << maxHeap.top() << "\n";
    }
    return 0;
}
