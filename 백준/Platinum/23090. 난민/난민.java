import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringBuilder sb = new StringBuilder();
	static StringTokenizer st;
	static int N;
	static long minSum, maxSum, sum;
	static Queue<Integer> minQ = new PriorityQueue<>((o1, o2) -> Integer.compare(o1, o2) * -1);
	static Queue<Integer> maxQ = new PriorityQueue<>();

	public static void main(String[] args) throws Exception {
		N = Integer.parseInt(br.readLine());
		minSum = maxSum = sum = 0L;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			if (minQ.isEmpty() || y <= minQ.peek()) {
				minQ.offer(y);
				minSum += y;
			} else {
				maxQ.offer(y);
				maxSum += y;
			}
			if (minQ.size() > maxQ.size() + 1) {
				int tmp = minQ.poll();
				minSum -= tmp;
				maxQ.offer(tmp);
				maxSum += tmp;
			}
			if (minQ.size() < maxQ.size()) {
				int tmp = maxQ.poll();
				maxSum -= tmp;
				minQ.offer(tmp);
				minSum += tmp;
			}
			sum += Math.abs(x);
			sb.append(minQ.peek()).append(" ").append(sum + sumY()).append("\n");
		}
		System.out.println(sb);
	}

	private static long sumY() {
		return (long)minQ.peek() * minQ.size() - minSum + maxSum - (long)minQ.peek() * maxQ.size();
	}
}


