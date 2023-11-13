import java.util.*;

class Solution {
    /*
    0: 비어있음 1: 벽으로 채워져 있음
    출발점: (0,0) 도착점: (N-1,N-1)
    도착점까지 갈 수 있도록 경주로 건설
    상하좌우 두 빈 칸을 연결하여 건설 가능, 벽이 있으면 건설 불가능
    
    빈 칸을 연결한 경로 -> 직선 도로
    직선 도로가 서로 직각으로 만나는 지점 -> 코너
    
    직선도로 -> 100원
    코너 -> 500원
    
    최소 비용 계산하기 -> 브루트포스, 백트래킹 + 브루트포스, O(2 * N),
    코너임을 확인해야 함 -> 3차원 방문 배열
    N: 0, E: 1, S: 2, W: 3
    각 칸마다 진입했던 방향을 숫자로 저장
    다음 칸을 넘어갈 때 매개변수로 (직전 진행방향, 다음 칸의 진행 방향) 전달, 직전 진행 방향과 다르다면 -> 코너 -> sum += 500;
    */ 
    boolean[][] visited = new boolean[26][26];
    int[] dx = {-1,0,1,0}, dy = {0,1,0,-1};
    int[][] dp = new int[26][26];
    int N, answer = Integer.MAX_VALUE;
    static int STRAIGHT = 100, CORNER = 500;
    
    public int solution(int[][] board) {
        N = board.length;
        for(int i=0;i<25;i++){
            for(int j=0;j<25;j++){
                dp[i][j] = Integer.MAX_VALUE;
            }
        }
        for(int i=1;i<=2;i++){
            dfs(0,0,0,i,board);
        }
        return answer;
    }
    
    private void dfs(int nowX, int nowY, int cost, int pastDir, int[][] board){
        if(dp[nowX][nowY] < cost)
            return;
        visited[nowX][nowY] = true;
        dp[nowX][nowY] = Math.min(dp[nowX][nowY], cost);
        if(nowX == N-1 && nowY == N-1){
            answer = Math.min(answer, cost);
        }
        for(int i=0;i<4;i++){
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= N) // 범위 밖
                continue;
            if(board[nextX][nextY] == 1)  // 벽
                continue;
            if(visited[nextX][nextY]) // 방문했었다면
                continue;
            if(pastDir != i)  // 코너
                dfs(nextX, nextY, cost + STRAIGHT + CORNER, i, board);
            else  // 직진
                dfs(nextX, nextY, cost + STRAIGHT, i, board);
        }
        visited[nowX][nowY] = false;
    }
}