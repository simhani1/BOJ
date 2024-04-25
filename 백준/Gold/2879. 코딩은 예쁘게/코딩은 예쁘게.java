import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, ans;
    private static int[] origin, goal, arr;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        origin = new int[N + 1];
        goal = new int[N + 1];
        arr = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            origin[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            goal[i] = Integer.parseInt(st.nextToken());
        }
        for (int i = 0; i < N; i++) {
            arr[i] = goal[i] - origin[i];
        }
        System.out.println(solve());
    }

    private static int solve() {
        ans = 0;
        while (true) {
            boolean flag = true;
            for (int i = 0; i < N; i++) {
                int std = arr[i];
                if (std == 0) {
                    continue;
                }
                flag = false;
                int minDiff = Math.abs(std);
                int j;
                for (j = i + 1; j < N; j++) {
                    int target = arr[j];
                    /* 부호가 동일한 경우 */
                    if (std * target > 0) {
                        minDiff = min(minDiff, min(std, target));
                    }
                    /* 부호가 다르거나 0을 만난 경우 */
                    else if (std * target <= 0) {
                        i = consume(i, j, minDiff);
                        break;
                    }
                }
                /* 끝까지 탐색한 경우 */
                if (j == N) {
                    i = consume(i, j, minDiff);
                }
            }
            if (flag) {
                return ans;
            }
        }
    }

    private static int consume(int start, int end, int diff) {
        ans += diff;
        for (int k = start; k < end; k++) {
            if (arr[k] < 0) {
                arr[k] += diff;
            } else {
                arr[k] -= diff;
            }
        }
        return end - 1;
    }

    private static int min(int a, int b) {
        return Math.min(Math.abs(a), Math.abs(b));
    }
}