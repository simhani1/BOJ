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
#define MAX 1000001
#define MOD 987654321
typedef long long ll;

int N;
priority_queue<ll> pqPlus, pqMinus;

void input(void)
{
    cin >> N;
    for (int i = 0, X; i < N; i++)
    {
        cin >> X;
        if (X < 0)
            pqMinus.push(X);
        else if (X > 0)
            pqPlus.push(-X);
        else
        {
            ll A = -123456789123, B = 123456789123;
            if (!pqMinus.empty())
                A = pqMinus.top();
            if (!pqPlus.empty())
                B = -pqPlus.top();
            if (pqMinus.empty() && pqPlus.empty())
            {
                cout << 0 << "\n";
                continue;
            }
            if (abs(A) <= abs(B))
            {
                cout << A << "\n";
                pqMinus.pop();
            }
            else
            {
                cout << B << "\n";
                pqPlus.pop();
            }
        }
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