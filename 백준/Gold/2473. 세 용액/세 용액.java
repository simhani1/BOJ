import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static List<Integer> list;
    private static int[] ans;
    private static final long INF = Long.MAX_VALUE;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        ans = new int[3];
        list = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            list.add(Integer.parseInt(st.nextToken()));
        }
        Collections.sort(list);
        solve();
        for (int i : ans) {
            sb.append(i).append(" ");
        }
        System.out.println(sb);
    }

    private static void solve() {
        long sum = INF;
        int water1, water2, water3;
        for (int i = 0; i < N - 2; i++) {
            int l = i + 1, r = N - 1;
            while (l < r) {
                water1 = list.get(i);
                water2 = list.get(l);
                water3 = list.get(r);
                long pSum = (long) water1 + water2 + water3;
                if (Math.abs(pSum) < Math.abs(sum)) {
                    ans[0] = water1;
                    ans[1] = water2;
                    ans[2] = water3;
                    sum = pSum;
                }
                if (pSum > 0) {
                    r--;
                } else if (pSum < 0) {
                    l++;
                } else {
                    return;
                }
            }
        }
    }

}