import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M;
    private static int[] arr;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        arr = new int[N + 2];
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int gender = Integer.parseInt(st.nextToken());
            int idx = Integer.parseInt(st.nextToken());
            changeSwitch(gender, idx);
        }
        for (int i = 1; i <= N; i++) {
            sb.append(arr[i])
                    .append(" ");
            if (i % 20 == 0) {
                sb.append("\n");
            }
        }
        System.out.println(sb.toString());
    }

    private static void changeSwitch(int gender, int idx) {
        if (gender == 1) {
            for (int i = idx; i <= N; i += idx) {
                arr[i] = arr[i] == 1 ? 0 : 1;
            }
        } else {
            arr[idx] = arr[idx] == 1 ? 0 : 1;
            int l = idx - 1;
            int r = idx + 1;
            while (1 <= l && r <= N) {
                if (arr[l] == arr[r]) {
                    arr[l] = arr[l] == 1 ? 0 : 1;
                    arr[r] = arr[r] == 1 ? 0 : 1;
                    l--;
                    r++;
                } else {
                    break;
                } 
            }
        }
    }
}