import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, K, ans;
    private static String[] arr;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());
        arr = new String[N + 1];
        for (int i = 0; i < N; i++) {
            arr[i] = br.readLine()
                    .replace("anta", "")
                    .replace("tica", "");
        }
        ans = 0;
        int bit = 0;
        bit |= 1 << ('a' - 'a');
        bit |= 1 << ('n' - 'a');
        bit |= 1 << ('t' - 'a');
        bit |= 1 << ('i' - 'a');
        bit |= 1 << ('c' - 'a');
        if (K >= 5) {
            solve(0, 5, bit);
        }
        System.out.println(ans);
    }

    private static void solve(int idx, int cnt, int bit) {
        if (cnt == K) {
            ans = Math.max(ans, counting(bit));
            return;
        }
        for (int i = idx; i < 26; i++) {
            if ((bit & 1 << i) == 0) {
                solve(i + 1, cnt + 1, bit | 1 << i);
            }
        }
    }

    private static int counting(int bit) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            String str = arr[i];
            boolean flag = true;
            for (int j = 0; j < str.length(); j++) {
                if ((bit & 1 << (str.charAt(j) - 'a')) == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                sum++;
            }
        }
        return sum;
    }
}