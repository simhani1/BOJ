#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
vector<vector<int>> answer;
bool arr[101][101][2];

bool install(int X, int Y, int type){
    // 기둥
    if(type == 0){
        if(Y == 0)
            return true;
        if(arr[X][Y-1][0])
            return true;
        if(arr[X-1][Y][1])
            return true;
        if(arr[X][Y][1])
            return true;   
        return false;
    }
    // 보
    else{
        if(arr[X][Y-1][0])
            return true;   
        if(arr[X+1][Y-1][0])
            return true;   
        if(arr[X-1][Y][1] && arr[X+1][Y][1])
            return true;   
        return false;
    }
}

void makeAnswer(){
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            for(int k=0;k<2;k++){
                if(arr[i][j][k]){
                    vector<int> tmp;
                    tmp.push_back(i);
                    tmp.push_back(j);
                    tmp.push_back(k);
                    answer.push_back(tmp);
                }
            }
        }
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N = n;
    for(auto i : build_frame){
        int X = i[0];
        int Y = i[1];
        int type = i[2];  // 0: 기둥, 1: 보
        int cmd = i[3];  // 0: 삭제, 1: 설치
        if(cmd == 1){
            if(install(X, Y, type))
                arr[X][Y][type] = true;
        }
        else if(cmd == 0){
            bool cannotRemove = false;
            arr[X][Y][type] = false;  // 일단 삭제
            for(int i=0;i<=N;i++){
                for(int j=0;j<=N;j++){
                    for(int k=0;k<2;k++){
                        // 기둥이나 보가 존재하는 경우 모든 좌표에 대하여 기둥, 보를 설치할 수만 있으면 삭제 가능
                        if(arr[i][j][k]){
                            if(!install(i, j, k))
                                cannotRemove = true;
                        }
                    }
                }
            }
            // 삭제 불가능
            if(cannotRemove)
                arr[X][Y][type] = true;
        }
    }
    makeAnswer();
    return answer;
}