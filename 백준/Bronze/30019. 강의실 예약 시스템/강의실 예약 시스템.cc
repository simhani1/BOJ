#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
using namespace std;
#define INF 123456789
#define MOD 1000000
typedef long long ll;

int N, M;
int arr[200001][2];

void input(void)
{
    cin >> N >> M;
    for (int i = 0, A, B, C; i < M; i++)
    {
        cin >> A >> B >> C;
        if (arr[A][0] == 0 && arr[A][1] == 0)
        {
            arr[A][0] = B;
            arr[A][1] = C;
        }
        if (arr[A][1] <= B && B < C){
            arr[A][0] = B;
            arr[A][1] = C;
            cout << "YES\n";
        }
        else if (arr[A][0] == B && arr[A][1] == C){
            arr[A][0] = B;
            arr[A][1] = C;
            cout << "YES\n";
        }
        else if (B < C && C <= arr[A][0]){
            arr[A][0] = B;
            arr[A][1] = C;
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    input();
    return 0;
}
