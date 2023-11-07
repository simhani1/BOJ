import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        String[] str = br.readLine().split(" ");
        int[] arr = new int[N + 10];
        for (int i = 1; i <= str.length; i++) {
            arr[i] = Integer.parseInt(str[i - 1]);
        }
        System.out.println(solve(N, arr));
    }

    private static int solve(int N, int[] arr) {
        int ans = N - 2;
        for (int i = 1; i <= N - 1; i++) {
            for (int j = i + 1; j <= N; j++) {
                // 등차가 정수여야 가능
                if ((arr[j] - arr[i]) % (j - i) != 0) {
                    continue;
                }
                int m = (arr[j] - arr[i]) / (j-i);
                int cnt = 0;
                for (int k = 1; k <= N; k++) {
                    int goal = (k - i) * m + arr[i];  // 등차수열로 만들기 위해 기대하는 값
                    // 기대값과 다르다면 바꿔야 함
                    if (arr[k] != goal) {
                        cnt++;
                    }
                }
                ans = Math.min(ans, cnt);
            }
        }
        return ans;
    }
}

