import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for (int i = 2; i < 10; i++) {
            if (isPrime(i)) {
                dfs(i, 1);
            }
        }
        System.out.println(sb.toString());
    }

    private static boolean isPrime(int num) {
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    private static void dfs(int num, int cnt) {
        // N자릿수까지 만들었다면
        if (cnt == N) {
            if (isPrime(num)) {
                sb.append(num)
                        .append("\n");
            }
            return;
        }
        int nextNum = num * 10;
        for (int i = 1; i < 10; i++) {
            if (isPrime(nextNum + i)) {
                dfs(nextNum + i, cnt + 1);
            }
        }
    }
}