import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M, areaCnt = 0, cctvCnt = 0, ans = 123456789;
    private static int[][] arr;
    private static CCTV[] cctvs = new CCTV[9];
    private static int[][] cctvDir = new int[9][];
    private static int[] dx = {-1, 0, 1, 0};
    private static int[] dy = {0, 1, 0, -1};
    private static int[][][] direction = {
            {},
            {{0}, {1}, {2}, {3}},
            {{0, 2}, {1, 3}},
            {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
            {{3, 0, 1}, {0, 1, 2}, {1, 2, 3}, {2, 3, 0}},
            {{0, 1, 2, 3}}
    };

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        arr = new int[N + 1][M + 1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                /* 빈 공간의 개수 저장 */
                if (arr[i][j] == 0) {
                    areaCnt++;
                }
                if (arr[i][j] != 0 && arr[i][j] != 6) {
                    /* x, y 위치의 cctc 타입 저장 */
                    cctvs[cctvCnt] = new CCTV(i, j, arr[i][j]);
                    cctvCnt++;
                }
            }
        }
        solve(0);
        System.out.println(ans);
    }

    private static void solve(int idx) {
        /* 모든 카메라의 방향을 지정한 경우 */
        if (idx == cctvCnt) {
            int[][] tmp = copyArr(arr);
            for (int i = 0; i < cctvCnt; i++) {
                /* 각 cctv마다 감시 가능 구역 표시 */
                for (int dir : cctvDir[i]) {
                    int nextX = cctvs[i].x + dx[dir];
                    int nextY = cctvs[i].y + dy[dir];
                    /* 감시하지 않았거나 이미 감시되는 영역을 감시할 수 있음 */
                    while (check(nextX, nextY) && tmp[nextX][nextY] != 6) {
                        tmp[nextX][nextY] = -1;
                        nextX += dx[dir];
                        nextY += dy[dir];
                    }
                }
            }
            /* 감시되는 영역 구하기 */
            int cnt = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (tmp[i][j] == 0) {
                        cnt++;
                    }
                }
            }
            ans = Math.min(ans, cnt);
            return;
        }
        for (int i = idx; i < cctvCnt; i++) {
            CCTV cctv = cctvs[i];
            for (int j = 0; j < direction[cctv.type].length; j++) {
                cctvDir[i] = direction[cctv.type][j];
                solve(i + 1);
            }
        }
    }

    private static boolean check(int nextX, int nextY) {
        return 0 <= nextX && nextX < N && 0 <= nextY && nextY < M;
    }

    private static int[][] copyArr(int[][] arr) {
        int[][] tmp = new int[N + 1][M + 1];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                tmp[i][j] = arr[i][j];
            }
        }
        return tmp;
    }

    static class CCTV {
        int x;
        int y;
        int type;

        public CCTV(int x, int y, int type) {
            this.x = x;
            this.y = y;
            this.type = type;
        }
    }
}