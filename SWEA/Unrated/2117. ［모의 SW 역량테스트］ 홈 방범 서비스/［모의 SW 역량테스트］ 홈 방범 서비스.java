import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Solution {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int T, N, M, ans;
    private static int[][] arr;
    private static Set<Home> set;

    static class Home {
        int x;
        int y;

        public Home(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static void main(String[] args) throws IOException {
        T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            ans = 0;
            st = new StringTokenizer(br.readLine());
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            arr = new int[N + 1][N + 1];
            set = new HashSet<>();
            for (int i = 0; i < N; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < N; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                    if (arr[i][j] == 1) {
                        set.add(new Home(i, j));
                    }
                }
            }
            for (int k = 1; k <= 2 * N - 1; k++) {
                int cost = (k * k) + (k - 1) * (k - 1);
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        int cnt = 0;
                        for (Home home : set) {
                            if (Math.abs(i - home.x) + Math.abs(j - home.y) < k) {
                                cnt++;
                            }
                        }
                        if (cnt * M >= cost) {
                            ans = Math.max(ans, cnt);
                        }
                    }
                }
            }
            sb.append("#").append(t).append(" ").append(ans).append("\n");
        }
        System.out.println(sb);
    }

}