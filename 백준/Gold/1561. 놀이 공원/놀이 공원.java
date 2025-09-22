import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	private static final int INF = 987654321;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, M;
	static int[] arr;

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		arr = new int[M];
		for (int i = 0; i < M; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		if (N <= M) {
			sb.append(N);
		} else {
			solve();
		}
		System.out.println(sb);
	}

	private static void solve() {
		long l = 1, r = 2_000_000_000 * 30L;
		long resultTime = 0L;
		while (l <= r) {
			long mid = (l + r) / 2L;
			if (check(mid)) {
				r = mid - 1;
				resultTime = mid;
			} else {
				l = mid + 1;
			}
		}

		long ret = M;
		for (int i = 0; i < M; i++) {
			ret += ((resultTime - 1) / arr[i]);
		}
		for (int i = 0; i < M; i++) {
			if (resultTime % arr[i] == 0) {
				ret++;
			}
			if (ret == N) {
				sb.append(i + 1);
				return;
			}
		}
	}

	private static boolean check(long time) {
		long cnt = M;
		for (int i = 0; i < M; i++) {
			cnt += (time / arr[i]);
		}
		return cnt >= N;
	}

}