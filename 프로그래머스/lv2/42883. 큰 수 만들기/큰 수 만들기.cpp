#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int ansSize = number.size() - k;
    int start = 0;
    for(int i=0; i<ansSize;i++){
        char maxNum = number[start];
        int maxIdx = start;
        for(int j=start; j<=i+k;j++){
            if(maxNum < number[j]){
                maxNum =  number[j];
                maxIdx = j;
            }
        }
        start = maxIdx+1;
        answer += number[maxIdx];
    }
    return answer;
}