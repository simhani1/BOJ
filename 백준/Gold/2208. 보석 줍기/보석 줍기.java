import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, M;
	static int[] arr, pSum, dp;

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N + 1];
		pSum = new int[N + 1];
		dp = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
			pSum[i] = pSum[i - 1] + arr[i];
		}
		dp[M] = pSum[M];
		int ans = Math.max(0, dp[M]);
		for (int i = M + 1; i <= N; i++) {
			dp[i] = Math.max(dp[i - 1] + arr[i], pSum[i] - pSum[i - M]);
			ans = Math.max(ans, dp[i]);
		}
		System.out.println(ans);
	}
}
