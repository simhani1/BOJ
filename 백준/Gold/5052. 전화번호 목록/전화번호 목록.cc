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

int T, N;
char arr[10000][11];

struct Trie
{
    Trie *node[10];
    bool finish;

    // 생성자
    Trie()
    {
        finish = false;
        for (int i = 0; i < 10; i++)
        {
            node[i] = NULL;
        }
    }

    // 소멸자
    ~Trie()
    {
        for (int i = 0; i < 10; i++)
        {
            if (node[i])
                delete node[i];
        }
    }

    void insert(char *str)
    {
        // 문자열을 끝까지 읽은 경우
        if (*str == '\0')
        {
            // 문자열의 끝을 알리는 finish변수
            finish = true;
            return;
        }
        int now = *str - '0';
        // 다음 노드가 없다면 생성
        if (node[now] == NULL)
            node[now] = new Trie();
        // 현재 노드의 자식으로 다음 문자를 삽입
        node[now]->insert(str + 1);
    }

    bool find(char *str)
    {
        // 문자열을 다 읽은 경우
        if (*str == '\0')
            return false;
        /*
        문자열 중간에서 종료되는 경우
        즉 해당 번호가 다른 번호의 접두어가 되는 경우
        일관성이 없음
        */
        if (finish == true)
            return true;
        int now = *str - '0';
        if (node[now] == NULL)
            return false;
        return node[now]->find(str + 1);
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> N;
        Trie *root = new Trie();
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
            root->insert(arr[i]);
        }
        for (int i = 0; i < N; i++)
        {
            if (root->find(arr[i]))
            {
                cout << "NO\n";
                break;
            }
            // 모든 문자열에 대해 일관성이 있는 경우
            else if (i == N - 1)
                cout << "YES\n";
        }
    }
    return 0;
}
