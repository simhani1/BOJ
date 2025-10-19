import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	private static final int INF = 987654321;
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, K, S;

	static PriorityQueue<Apt> left, right;

	static class Apt {
		int pos, cnt;

		public Apt(int pos, int cnt) {
			this.pos = pos;
			this.cnt = cnt;
		}
	}

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		left = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.pos, o2.pos));
		right = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.pos, o2.pos) * -1);
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int pos = Integer.parseInt(st.nextToken());
			int cnt = Integer.parseInt(st.nextToken());
			if (pos < S) {
				left.offer(new Apt(pos, cnt));
			} else  {
				right.offer(new Apt(pos, cnt));
			}
		}
		System.out.println(pickupLeft() + pickupRight());
	}

	private static int pickupLeft() {
		int ret = 0;
		while (!left.isEmpty()) {
			int idx = INF;
			int availableCnt = K;
			while (!left.isEmpty()) {
				Apt apt = left.poll();
				idx = Math.min(idx, apt.pos);
				if (availableCnt < apt.cnt) {
					left.offer(new Apt(apt.pos, apt.cnt - availableCnt));
					break;
				}
				availableCnt -= apt.cnt;
			}
			ret += Math.abs(S - idx) * 2;
		}
		return ret;
	}

	private static int pickupRight() {
		int ret = 0;
		while (!right.isEmpty()) {
			int idx = 0;
			int availableCnt = K;
			while (!right.isEmpty()) {
				Apt apt = right.poll();
				idx = Math.max(idx, apt.pos);
				if (availableCnt < apt.cnt) {
					right.offer(new Apt(apt.pos, apt.cnt - availableCnt));
					break;
				}
				availableCnt -= apt.cnt;
			}
			ret += Math.abs(S - idx) * 2;
		}
		return ret;
	}
}
