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

using namespace std;

int K;
int node[1024]; // 1 ~ 1023번까지 저장 가능
bool visited[1024];

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> K;
    //중위순회 결과 저장
    for (int i = 1; i < pow(2, K); i++)
    {
        cin >> node[i];
    }
    // 각 레벨에 있는 빌딩 번호 출력
    int std = pow(2, K) / 2;
    for (int i = 0; i < K; i++)
    {
        for (int j = std; j < pow(2, K); j += std)
        {
            if (!visited[j])
            {
                cout << node[j] << " ";
                visited[j] = true;
            }
        }
        std /= 2;
        cout << "\n";
    }
    return 0;
}