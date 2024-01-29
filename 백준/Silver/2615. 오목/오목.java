import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static StringTokenizer st;
    private static int N = 19;
    private static int[][] arr = new int[N + 2][N + 2];
    private static int[] dx = { 1, 1, 0, -1 };
    private static int[] dy = { 0, 1, 1, 1 };
    private static boolean flag = false;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 1; i <= N; i++) {
            // 한 줄
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        // solve
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][j] == 0) {
                    continue;
                }
                for (int dir = 0; dir < 4; dir++) {
                    int nextX = i + dx[dir];
                    int nextY = j + dy[dir];
                    // 종류, 시작 x, 시작 y, 다음 x, 다음 y, 진행방향, 카운트
                    dfs(arr[i][j], i, j, nextX, nextY, dir, 1);
                }
            }
        }
        if(flag == false) {
            System.out.println(0);
        }
    }

    public static void dfs(int prevType, int startX, int startY, int nowX, int nowY, int dir, int cnt) {
        // 범위 이탈한 경우
        if (nowX < 0 || nowX > N + 1 || nowY < 0 || nowY > N + 1)
            return;
        int nowType = arr[nowX][nowY];
        // 현재가 0이거나 직전까지의 바둑알과 색이 다른 경우
        if (prevType != nowType) {
            // 육목 이상이라면 종료
            if (cnt == 5) {
                if (dir == 0) {
                    if (arr[startX - 1][startY] == prevType) {
                        return;
                    }
                } else if (dir == 1) {
                    if (arr[startX - 1][startY - 1] == prevType) {
                        return;
                    }
                } else if (dir == 2) {
                    if (arr[startX][startY - 1] == prevType) {
                        return;
                    }
                } else if (dir == 3) {
                    if (arr[startX + 1][startY - 1] == prevType) {
                        return;
                    }
                }
                // 오목이라면
                flag = true;
                System.out.println(prevType);
                System.out.println(startX + " " + startY);
            }
            return;
        }
        dfs(nowType, startX, startY, nowX + dx[dir], nowY + dy[dir], dir, cnt + 1);
    }
}