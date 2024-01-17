import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N;
    static int K;
    static int ans = 0;
    static List<Integer> arr = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        for (int i = 0; i < K - 1; i++) {
            N -= (int) Math.pow(2, (int) Math.floor(Math.log(N) / Math.log(2)));
        }
        ans = (int) Math.pow(2, (int) Math.ceil(Math.log(N) / Math.log(2))) - N;
        System.out.println(ans);
    }
}