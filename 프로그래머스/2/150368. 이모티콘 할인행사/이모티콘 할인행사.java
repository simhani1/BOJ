import java.util.*;

class Solution {
    /*
    1순위: 가입자를 최대한 늘리기
	2순위: 판매액 최대한 늘리기
    
    N명 사용자에게 M개를 할인판매
    10, 20, 30, 40% 할인
    
    구매 기준
    1. 일정 비율 이상 할인하는 이모티콘 모두 구매
    2. 이모티콘 구매 비용의 합이 일정 가격 이상이 된다면, 구매를 취소하고 플러스 서비스에 가입
    
    users: 구매 기준,  emoticons: 정가
    
    조합을 사용하여 각 이모티콘의 할인율을 적용한 이후 결과를 체크한다.
    결과 체크의 기준은 1순위, 2순위를 기준삼아서 판단하기
    if(새로운 가입자 수 > 과거 가입자 수)
        정답
    else if(새로운 가입자 수 == 과거 가입자 수){
        if(새로운 판매액 > 과거 판매액)
            정답
    }
    */    
    int N, M;
    int ratio[] = new int[10];
    int serviceCnt = 0, sum = 0;
    
    public int[] solution(int[][] users, int[] emoticons) {
        N = users.length;
        M = emoticons.length;
        discount(0, 0, users, emoticons, ratio);
        int[] answer = {serviceCnt, sum}; 
        return answer;
    }
    
    private void discount(int idx, int cnt, int[][] users, int[] emoticons, int[] r){
        if(cnt == M){
            int tmpServiceCnt = 0, tmpSum = 0;
            
            //모든 사람에 대해 이모티콘 판매액, 서비스 가입자 수 계산
            for(int i=0;i<N;i++){
                int stdRatio = users[i][0];
                int stdPrice = users[i][1];
                int userSum = 0;
                // 이모티콘 가격 계산
                for(int j=0;j<M;j++){
                    if(r[j] < stdRatio)  // 기준 할인 벗어나면 구매하지 않음
                        continue;
                    userSum += (emoticons[j] * (100 - r[j]) / 100);
                }
                if(userSum >= stdPrice)
                    tmpServiceCnt++;  // 서비스 가입
                else
                    tmpSum += userSum;  // 이모티콘 구매
            }
            // 정답 갱신 과정
            if(tmpServiceCnt > serviceCnt){
                serviceCnt = tmpServiceCnt;
                sum = tmpSum;
            }
            else if(tmpServiceCnt == serviceCnt){
                if(tmpSum > sum){
                    serviceCnt = tmpServiceCnt;
                    sum = tmpSum;
                }
            }
            return;
        }
        for(int i=10;i<=40;i+=10){
            r[idx] = i;
            discount(idx + 1, cnt + 1, users, emoticons, r);
            r[idx] = 0;
        }
    }
}