import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * @author
 * 심종한
 * @date
 * 2024-01-30
 * @link
 * https://swexpertacademy.com/main/talk/solvingClub/problemView.do?contestProbId=AV14ABYKADACFAYh&solveclubId=AY0LFFoqrIIDFAXz&problemBoxTitle=0129%EC%A3%BC&problemBoxCnt=4&probBoxId=AY0LFFoqrIMDFAXz+
 * @keyword_solution
 * 1. 도착점에서 출발점을 찾아가는 탐색을 진행하면 한번에 정답 발견
 * 2. 위쪽으로 탐색 중 -> 좌우에 1이 있는지 판단해야 함
 * 3. 왼쪽 또는 오른쪽으로 탐색 중 -> 위쪽에 1이 있는지 판단해야 함
 *    배열의 범위를 벗어나는지, 1인지 판단해야 함
 * @input
 * 2가 입력되는 순간 도착지점의 죄표 저장할 것
 * @output
 * 문제에서 말하는 X좌표는 현재 내 배열의 Y좌표와 동일하다는 점
 * @time_complex
 * O(N)?
 * @perf
 * 메모리 30,880kb 시간: 152ms
 */
public class Solution {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N = 100, T;
    private static int goalX, goalY;
    private static int[][] arr = new int[101][101];
    private static int[] dx = {-1, 0, 0};
    private static int[] dy = {0, -1, 1};

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        for (int t = 1; t <= 10; t++) {
            T = Integer.parseInt(br.readLine());
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                    if (arr[i][j] == 2) {
                        goalX = i;
                        goalY = j;
                    }
                }
            }
            dfs(goalX, goalY, 0);
        }
        System.out.println(sb.toString());
    }

    /**
     * @param nowX 현재 x좌표
     * @param nowY 현재 y좌표
     * @param dir 0: 위, 1: 왼쪽, 2: 오른쪽
     */
    private static void dfs(int nowX, int nowY, int dir) {
        if (nowX == 0) {
            sb.append("#")
                    .append(T)
                    .append(" ")
                    .append(nowY)
                    .append("\n");
            return;
        }
        // 죄우 탐색 필요
        dir = checkLeftAndRight(nowX, nowY, dir);
        dfs(nowX + dx[dir], nowY + dy[dir], dir);
    }

    private static int checkLeftAndRight(int nowX, int nowY, int dir) {
        int nextX, nextY;
        // 왼쪽 가로로 진행 중 -> 우측 탐색 == 위쪽 탐색
        // 오른쪽 가로로 진행 중 -> 왼쪽 탐색 == 위쪽 탐색
        if (dir != 0) {
            nextX = nowX + dx[0];
            nextY = nowY + dy[0];
            return canMove(nextX, nextY) ? 0 : dir;
        }
        // 위쪽으로 진행 중 -> 좌우 탐색
        // left
        nextX = nowX + dx[1];
        nextY = nowY + dy[1];
        if (canMove(nextX, nextY)) {
            return 1;
        }
        // right
        nextX = nowX + dx[2];
        nextY = nowY + dy[2];
        if (canMove(nextX, nextY)) {
            return 2;
        }
        return dir;  // 좌우 0이면 유지
    }

    private static boolean canMove(int nextX, int nextY) {
        return check(nextX, nextY) && arr[nextX][nextY] == 1;
    }

    private static boolean check(int nextX, int nextY) {
        return 0 <= nextX && nextX < N && 0 <= nextY && nextY < N;
    }
}