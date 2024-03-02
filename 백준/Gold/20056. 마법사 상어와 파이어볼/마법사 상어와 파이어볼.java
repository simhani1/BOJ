import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N, M, K;
    private static List<FireBall>[][] arr;
    private static List<FireBall> fireBallList = new ArrayList<>();
    private static int[] dx = {-1, -1, 0, 1, 1, 1, 0, -1};
    private static int[] dy = {0, 1, 1, 1, 0, -1, -1, -1};
    static class FireBall {
        int x;
        int y;
        int weight;
        int speed;
        int direction;

        public FireBall(int x, int y, int weight, int speed, int direction) {
            this.x = x;
            this.y = y;
            this.weight = weight;
            this.speed = speed;
            this.direction = direction;
        }
    }

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new ArrayList[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                arr[i][j] = new ArrayList<>();
            }
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()) - 1;
            int y = Integer.parseInt(st.nextToken()) - 1;
            int weight = Integer.parseInt(st.nextToken());
            int speed = Integer.parseInt(st.nextToken());
            int direction = Integer.parseInt(st.nextToken());
            FireBall fireBall = new FireBall(x, y, weight, speed, direction);
            fireBallList.add(fireBall);
        }
        for (int i = 0; i < K; i++) {
            move();
            division();
        }
        System.out.println(sumWeight());
    }

    private static void move() {
        for (FireBall fireBall : fireBallList) {
            int nextX = (N + fireBall.x + dx[fireBall.direction] * (fireBall.speed % N)) % N;
            int nextY = (N + fireBall.y + dy[fireBall.direction] * (fireBall.speed % N)) % N;
            fireBall.x = nextX;
            fireBall.y = nextY;
            arr[nextX][nextY].add(fireBall);
        }
    }

    private static void division() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                /* 1개 이하인 경우 */
                if (arr[i][j].size() < 2) {
                    arr[i][j].clear();
                    continue;
                }
                /* 하나로 합치기 */
                int totalWeight = 0, totalSpeed = 0, size = arr[i][j].size();
                int oddCnt = 0, evenCnt = 0;
                for (FireBall fireBall : arr[i][j]) {
                    totalWeight += fireBall.weight;
                    totalSpeed += fireBall.speed;
                    if (fireBall.direction % 2 == 0) {
                        evenCnt++;
                    } else {
                        oddCnt++;
                    }
                    fireBallList.remove(fireBall);
                }
                arr[i][j].clear();
                /* 분할 */
                int tmpWeight = totalWeight / 5;
                int tmpSpeed = totalSpeed / size;
                if (tmpWeight == 0) {
                    continue;
                }
                /* 방향 결정 */
                if (oddCnt == 0 || evenCnt == 0) {
                    /* 방향 0, 2, 4, 6 */
                    for (int dir = 0; dir < 8; dir += 2) {
                        fireBallList.add(new FireBall(i, j, tmpWeight, tmpSpeed, dir));
                    }
                } else {
                    /* 방향 1, 3, 5, 7 */
                    for (int dir = 1; dir < 8; dir += 2) {
                        fireBallList.add(new FireBall(i, j, tmpWeight, tmpSpeed, dir));
                    }
                }
            }
        }
    }

    private static int sumWeight() {
        int sum = 0;
        for (FireBall fireBall : fireBallList) {
            sum += fireBall.weight;
        }
        return sum;
    }
}