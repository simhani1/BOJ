import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int M, N, L;
    private static int[] hunter;
    static class Pos {
        int x;
        int y;

        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws Exception {
        /* input */
        st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        L = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        hunter = new int[M];
        for (int i = 0; i < M; i++) {
            hunter[i] = Integer.parseInt(st.nextToken());
        }
        Arrays.sort(hunter);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            ans += matchHunter(x, y);
        }
        System.out.println(ans);
    }

    private static int matchHunter(int x, int y) {
        int cnt = 0;
        int l = 0;
        int r = M - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            int dis = Math.abs(x - hunter[mid]) + y;
            if (dis <= L) {
                cnt++;
                break;
            }
            if (x <= hunter[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return cnt;
    }

}