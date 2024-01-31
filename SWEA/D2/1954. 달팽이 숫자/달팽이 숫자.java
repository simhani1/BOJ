import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @author 심종한
 * @date 2024-01-31
 * @link https://swexpertacademy.com/main/talk/solvingClub/problemView.do?contestProbId=AV5PobmqAPoDFAUq&solveclubId=AY0LFFoqrIIDFAXz&problemBoxTitle=0129%EC%A3%BC&problemBoxCnt=5&probBoxId=AY0LFFoqrIMDFAXz
 * @keyword_solution
 * 동(0) -> 남(1) -> 서(2) -> 북(3) 순서로 회전
 * 범위를 벗어나거나 또는 이미 방문한 곳이라면 -> 다음 방향으로 회전
 * mod 연산을 사용하여 자동 방향 전환
 * @input
 * @output
 * 배열 순회하며 출력하기
 * @time_complex O(N^2)
 * @perf 메모리: 18,652 시간: 104ms
 */
public class Solution {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int T, N;
    private static int[][] arr;
    private static int[] dx = {0, 1, 0, -1};
    private static int[] dy = {1, 0, -1, 0};
    private static boolean[][] visited;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            N = Integer.parseInt(br.readLine());
            arr = new int[N + 2][N + 2];
            visited = new boolean[N + 2][N + 2];
            dfs(1, 1, 1, 0);
            sb.append("#")
                    .append(t)
                    .append("\n");
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    sb.append(arr[i][j])
                            .append(" ");
                }
                sb.append("\n");
            }
        }
        System.out.println(sb.toString());
    }

    private static void dfs(int nowX, int nowY, int num, int dir) {
        visited[nowX][nowY] = true;
        arr[nowX][nowY] = num;
        int nextX = nowX + dx[dir];
        int nextY = nowY + dy[dir];
        int nextDir = (dir + 1) % 4;
        if (num == N * N) {
            return;
        }
        if (visited[nextX][nextY] || !check(nextX, nextY)) {
            dfs(nowX + dx[nextDir], nowY + dy[nextDir], num + 1, nextDir);
        } else {
            dfs(nextX, nextY, num + 1, dir);
        }
    }

    private static boolean check(int nextX, int nextY) {
        return 1 <= nextX && nextX <= N && 1 <= nextY && nextY <= N;
    }
}