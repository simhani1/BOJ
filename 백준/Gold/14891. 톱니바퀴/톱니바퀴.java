import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int K;
    private static int[] status;
    private static int arr[][] = new int[5][8];

    public static void main(String[] args) throws Exception {
        for (int i = 1; i <= 4; i++) {
            char[] chars = br.readLine().toCharArray();
            for (int j = 0; j < 8; j++) {
                arr[i][j] = chars[j] - '0';
            }
        }
        K = Integer.parseInt(br.readLine());
        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            /* num: 톱니 번호, dir: 1(시계), -1(반시계)*/
            int num = Integer.parseInt(st.nextToken());
            int dir = Integer.parseInt(st.nextToken());
            solve(num, dir);
        }
        int sum = 0;
        for (int i = 1; i <= 4; i++) {
            sum += arr[i][0] == 1 ? Math.pow(2, i - 1) : 0;
        }
        System.out.println(sum);
    }

    private static void solve(int num, int dir) {
        status = new int[5];
        status[num] = dir;
        if (num == 1) {
            checkRight(num);
        } else if (num == 2 || num == 3) {
            /* 왼쪽으로 탐색 */
            checkLeft(num);
            /* 오른쪽으로 탐색 */
            checkRight(num);
        } else if (num == 4) {
            checkLeft(num);
        }
        /* 상태에 따라 회전 */
        spin();
    }

    private static void checkLeft(int tmp) {
        /* 왼쪽으로 탐색 */
        while (tmp >= 1) {
            if (arr[tmp][6] != arr[tmp - 1][2]) {
                status[tmp - 1] = status[tmp] * -1;
                tmp--;
                continue;
            }
            break;
        }
    }

    private static void checkRight(int tmp) {
        /* 오른쪽으로 탐색 */
        while (tmp <= 3) {
            if (arr[tmp][2] != arr[tmp + 1][6]) {
                status[tmp + 1] = status[tmp] * -1;
                tmp++;
                continue;
            }
            break;
        }
    }

    private static void spin() {
        for (int i = 1; i <= 4; i++) {
            int[] tmp = new int[8];
            if (status[i] == 1) {
                /* 시계방향 */
                for (int j = 1; j <= 8; j++) {
                    tmp[j % 8] = arr[i][j - 1];
                }
                arr[i] = tmp;
            } else if (status[i] == -1) {
                /* 반시계 방향 */
                for (int j = 0; j < 8; j++) {
                    tmp[j] = arr[i][(j + 1) % 8];
                }
                arr[i] = tmp;
            }
        }
    }
}