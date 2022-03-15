#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
#include <time.h>
#include <map>

using namespace std;

int N, M, V;
int snail[200001];

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> N >> M >> V;
    //각 노드의 정수 입력
    for (int i = 1; i <= N; i++) {
        cin >> snail[i];
    }
    //순환되는 노드의 개수 저장
    int cycle = N - V + 1;
    while (M--) {
        //이동한 횟수를 입력받기 때문에 배열에서 C+1번째 값을 출력해야 한다
        int C;
        cin >> C;
        if (C < N)
            cout << snail[C + 1] << '\n';
        else
            cout << snail[V + (C + 1 - V) % cycle] << '\n';
    }
    return 0;
}