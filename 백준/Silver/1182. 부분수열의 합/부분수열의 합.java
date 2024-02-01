import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, S, ans;
	static int[] arr;
	static int flag = 0;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		ans = 0;
		method(0, 0);
		System.out.println(ans);
	}

	private static void method(int flag, int cnt) {

		if (cnt == N) {
			if (flag == 0)
				return;
			int sum = 0;
			for (int i = 0; i < N; i++) {
				if (((1 << i) & flag) > 0) {
					sum += arr[i];
				}
			}
			if (sum == S)
				ans++;
			return;
		}
		method(flag, cnt + 1);
		flag = (1 << cnt) | flag;
		method(flag, cnt + 1);
	}
}