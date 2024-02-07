import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int T, N;
    private static final int PAPER_SIZE = 10;
    private static final int MAX_SIZE = 100;
    private static int[][] arr = new int[110][110];

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        int x = 0, y = 0;
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            y = Integer.parseInt(st.nextToken());
            x = Integer.parseInt(st.nextToken());
            arr[x][y]++;
            arr[x + PAPER_SIZE][y]--;
            arr[x][y + PAPER_SIZE]--;
            arr[x + PAPER_SIZE][y + PAPER_SIZE]++;
        }
        for (int i = 0; i <= MAX_SIZE; i++) {
            for (int j = 1; j <= MAX_SIZE; j++) {
                arr[i][j] += arr[i][j - 1];
            }
        }
        for (int j = 0; j <= MAX_SIZE; j++) {
            for (int i = 1; i <= MAX_SIZE; i++) {
                arr[i][j] += arr[i - 1][j];
            }
        }
        int ans = 0;
        for (int i = 0; i <= MAX_SIZE; i++) {
            for (int j = 0; j <= MAX_SIZE; j++) {
                if (arr[i][j] != 0) {
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }
}