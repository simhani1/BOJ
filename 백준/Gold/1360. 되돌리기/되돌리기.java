import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int N;
	static History[] arr;
	static class History {
		int time;
		String val;

		public History(int time, String val) {
			this.time = time;
			this.val = val;
		}

		@Override
		public String toString() {
			return "History{" +
				"time=" + time +
				", val='" + val + '\'' +
				'}';
		}
	}
	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(br.readLine());
		arr = new History[N + 1];
		String now = "";
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			String cmd = st.nextToken();
			if ("type".equals(cmd)) {
				String c = st.nextToken();
				int time = Integer.parseInt(st.nextToken());
				now = now + c;
				arr[i] = new History(time, now);
			} else {
				int diff = Integer.parseInt(st.nextToken());
				int time = Integer.parseInt(st.nextToken());
				String val = "";
				for (int j = i - 1; j >= 0; j--) {
					if (arr[j].time < time - diff) {
						val = arr[j].val;
						break;
					}
				}
				arr[i] = new History(time, val);
				now = val;
			}
		}
		System.out.println(arr[N - 1].val);
	}
}


