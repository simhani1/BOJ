import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, K;
    private static PriorityQueue<Diamond> diamonds;
    private static List<Diamond> diamondList = new ArrayList<>();
    private static int[] bag;

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        /* 무게 오름차순 */
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            diamondList.add(new Diamond(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
        }
        Collections.sort(diamondList, (d1, d2) -> Integer.compare(d1.weight, d2.weight));

        bag = new int[K];
        for (int i = 0; i < K; i++) {
            bag[i] = Integer.parseInt(br.readLine());
        }

        /* 무게 오름차순 */
        Arrays.sort(bag);

        System.out.println(solve());
    }

    private static long solve() {
        PriorityQueue<Diamond> pq = new PriorityQueue<>((o1, o2) -> Integer.compare(o1.price, o2.price) * -1);
        /* 가격의 총합 <= 300,000,000,000 */
        long sum = 0;
        int idx = 0;
        for (int i = 0; i < K; i++) {
            int bagLimit = bag[i];
            while (idx < N) {
                Diamond diamond = diamondList.get(idx);
                if (diamond.weight <= bagLimit) {
                    pq.offer(diamond);
                    idx++;
                    continue;
                }
                break;
            }
            if (!pq.isEmpty()) {
                sum += pq.poll().price;
            }
        }
        return sum;
    }

    static class Diamond {
        int weight;
        int price;

        public Diamond(int weight, int price) {
            this.weight = weight;
            this.price = price;
        }
    }
}