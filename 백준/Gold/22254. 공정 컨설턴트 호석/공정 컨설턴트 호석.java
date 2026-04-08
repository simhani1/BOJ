import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int N, X;
	static int[] arr;

	public static void main(String[] args) throws Exception {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		X = Integer.parseInt(st.nextToken());

		st = new StringTokenizer(br.readLine());
		arr = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}

		// K개의 라인으로 X시간 이내에 제작이 가능하냐 불가하냐
		// 1개 ~ N개
		int ans = Integer.MAX_VALUE;
		int l = 1, r = N;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (isPossible(mid)) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}

		System.out.println(ans);
	}

	private static boolean isPossible(int val) {
		Queue<Long> pq = new PriorityQueue<>();
		for (int i = 0; i < val; i++) {
			pq.offer(0L);
		}

		for (int i = 0; i < N; i++) {
			long now = pq.poll();
			now += arr[i];
			pq.offer(now);
		}

		long maxTime = 0;
		while (!pq.isEmpty()) {
			maxTime = pq.poll();
		}
        
		return maxTime <= X;
	}
}