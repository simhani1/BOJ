import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, K;
	static int[] arr;

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		arr = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int l = 0, r = 0, cnt = 0, ret = 0;
        // 구간 내에 홀수가 최대 K개만 있을 때 길이의 최댓값 갱신 
		while (r < N) {
			if (cnt <= K) {
				if (arr[r] % 2 == 1) {
					cnt++;
				}
				r++;
			} else {
				if (arr[l] % 2 == 1) {
					cnt--;
				}
				l++;
			}
			ret = Math.max(ret, r - l - cnt);
		}
		System.out.println(ret);
	}
}
