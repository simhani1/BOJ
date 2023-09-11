#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check[51];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string a, b;
    cin >> a >> b;

    int idx = b.length() - 1;
    for (int i = a.length() - 1; i >= 0; i--)
    {
        if (a[i] == b[idx])
        {
            check[i] = true;
            idx--;
        }
    }

    int ans = 0;

    while (true)
    {
        bool find = false;
        for (int i = a.length() - 1; i >= 0; i--)
        {
            if (check[i] == true)
                continue;
            if (a[i] == b[idx])
            {
                check[i] = true;
                idx--;
                ans++;
                find = true;
                break;
            }
        }

        if (idx < 0)
            break;

        if (find == false)
        {
            cout << "-1";
            return 0;
        }
    }

    cout << ans;
    return 0;
}