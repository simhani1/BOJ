import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static long N, num, sum;

    public static void main(String[] args) throws IOException {
        N = Long.parseLong(br.readLine());
        num = sum = 0;
        for (num = 1; ; num++) {
            if (sum > N) {
                break;
            }
            sum += num;
        }
        System.out.println(num - 2);
    }
    
}