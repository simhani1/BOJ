import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	private static final int INF = 987654321;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int L, N, K;
	static int[] arr;

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		L =  Integer.parseInt(st.nextToken());
		N =  Integer.parseInt(st.nextToken());
		K =  Integer.parseInt(st.nextToken());
		arr = new int[N + 2];
		st = new StringTokenizer(br.readLine());
		arr[0] = 0;
		arr[N + 1] = L;
		for (int i = 1; i <= N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int ret = INF;
		int l = 1, r = L;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (check(mid)) {
				ret = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		System.out.println(ret);
	}

	private static boolean check(int mid) {
		int cnt = 0, energy = mid;
		for (int i = 1; i <= N + 1; i++) {
			int dist = arr[i] - arr[i - 1];
			// 진행 불가
			if (mid < dist) {
				return false;
			}
			if (energy >= dist) {
				energy -= dist;
			} else {
				energy = mid - dist;
				cnt++;
			}
		}
		return cnt <= K;
	}
}
