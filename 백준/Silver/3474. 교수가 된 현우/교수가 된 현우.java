import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int T, N;

    public static void main(String[] args) throws Exception {
        T = Integer.parseInt(br.readLine());
        while (T-- > 0) {
            N = Integer.parseInt(br.readLine());
            int two = 0, five = 0;
            for (int i = 2; i <= N; i *= 2) {
                two += (N / i);
            }
            for (int i = 5; i <= N; i *= 5) {
                five += (N / i);
            }
            sb.append(Math.min(two, five)).append("\n");
        }
        System.out.println(sb);
    }

}