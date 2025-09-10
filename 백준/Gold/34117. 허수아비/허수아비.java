import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static StringBuilder sb = new StringBuilder();
	static int N, P;
	static int[] arr, ans;
	static Queue<Integer> pq = new PriorityQueue<>();

	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		P = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		arr = new int[N];
		ans = new int[N];
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum += arr[i];
			pq.offer(arr[i]);
			while (!pq.isEmpty() && sum - pq.peek() >= P) {
				sum -= pq.poll();
			}
			sb.append(sum >= P ? pq.size() : -1).append(" ");
		}
		System.out.println(sb);
	}
}