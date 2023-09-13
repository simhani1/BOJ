#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int pSum[1000001];

// 사이 원소를 모두 포함해야함
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(sequence.size() - 1);

    int l = 0, r = 1, sum = sequence[0];
    while(l < r && r <= sequence.size()){
        if(sum >= k){
            if(sum == k && (r - 1 - l < answer[1] - answer[0])){
                answer[0] = l;
                answer[1] = r - 1;
            }
            sum -= sequence[l++];
        }
        else if(sum < k)
            sum += sequence[r++];
    }
    return answer;
}