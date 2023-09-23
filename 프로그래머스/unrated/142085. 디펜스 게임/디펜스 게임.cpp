#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int> pq;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int sum = 0;
    for(int i=0;i<enemy.size();i++){
        answer++;
        pq.push(-enemy[i]);
        if(pq.size() > k){
            sum += -pq.top();
            pq.pop();
        }
        if(sum > n){
            answer--;
            break;
        }
    }
    return answer;
}