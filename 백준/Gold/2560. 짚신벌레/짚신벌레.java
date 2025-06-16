import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int A, B, D, N;
    static int[] arr;
    static int MOD = 1000;

    public static void main(String[] args) throws IOException {
        st = new StringTokenizer(br.readLine());
        A =  Integer.parseInt(st.nextToken());
        B =  Integer.parseInt(st.nextToken());
        D =  Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        arr = new int[N + 1];
        arr[0] = 1;
        for (int i = 1; i <= N; i++) {
            if (i < A) {
                arr[i] = arr[i - 1];
            } else if (i < B) {
                arr[i] = arr[i - 1] + arr[i - A];
            } else {
                arr[i] = arr[i - 1] + arr[i - A] - arr[i - B];
            }
            arr[i] = (arr[i] + MOD) % MOD;
        }
        if (N >= D) {
            System.out.println((arr[N] - arr[N - D] + MOD) % MOD);
        } else {
            System.out.println(arr[N]);
        }
    }
}
