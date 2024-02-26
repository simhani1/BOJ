import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.*;
import java.util.StringTokenizer;

public class Main {

	private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	private static StringTokenizer st;
	private static ArrayDeque<Job> dq = new ArrayDeque<>();
	private static int N;
    
	static class Job {
		int point;
		int time;

		public Job(int point, int time) {
			super();
			this.point = point;
			this.time = time;
		}

		public void minusTime() {
			this.time--;
		}

		public boolean isFinished() {
			return this.time == 0;
		}

		@Override
		public String toString() {
			return "Job [point=" + point + ", time=" + time + "]";
		}
	}

	public static void main(String[] args) throws IOException {

		N = Integer.parseInt(br.readLine());

		int ans = 0;
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			int type = Integer.parseInt(st.nextToken());
			if (type == 0) {
				if (!dq.isEmpty()) {
					Job nowJob = dq.peekLast();
					nowJob.minusTime();
					if (nowJob.isFinished()) {
						ans += nowJob.point;
						dq.pollLast();
					}
				}
			} else {
				int point = Integer.parseInt(st.nextToken());
				int time = Integer.parseInt(st.nextToken());
				Job newJob = new Job(point, time);
				newJob.minusTime();
				if (newJob.isFinished()) {
					ans += point;
					continue;
				}
				dq.offerLast(newJob);
			}
		}
		System.out.println(ans);
	}
}