import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static long N;
    private static Queue<Long> maxHeap = new PriorityQueue<>((o1, o2) -> Long.compare(o1, o2) * -1);
    private static Queue<Long> minHeap = new PriorityQueue<>();

    public static void main(String[] args) throws Exception {
        N = Long.parseLong(br.readLine());
        long ans = 0;
        for (int i = 0; i < N; i++) {
            long num = Integer.parseInt(br.readLine());
            if (num > 1) {
                maxHeap.offer(num);
            } else if (num <= 0) {
                minHeap.offer(num);
            } else {
                ans++;
            }
        }
        while (!maxHeap.isEmpty()) {
            if (maxHeap.size() == 1) {
                ans += maxHeap.poll();
                continue;
            }
            ans += (maxHeap.poll() * maxHeap.poll());
        }
        while (!minHeap.isEmpty()) {
            if (minHeap.size() == 1) {
                ans += minHeap.poll();
                continue;
            }
            ans += (minHeap.poll() * minHeap.poll());
        }
        System.out.println(ans);
    }

}