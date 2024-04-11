import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int N;
    private static List<Node> list = new ArrayList<>();

    static class Node {
        int num;
        int idx;

        public Node(int num, int idx) {
            this.num = num;
            this.idx = idx;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "num=" + num +
                    ", idx=" + idx +
                    '}';
        }
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        for (int i = 0; i < N; i++) {
            int num = Integer.parseInt(br.readLine());
            list.add(new Node(num, i));
        }
        Collections.sort(list, (o1, o2) -> Integer.compare(o1.num, o2.num));
        int ans = 0;
        for (int i = 0; i < N; i++) {
            Node node = list.get(i);
            int idx = node.idx;
            /* 정렬되었을 때보다 현재 위치가 더 뒤쪽인 경우 */
            if (i < idx) {
                ans = Math.max(ans, idx - i);
            }
        }
        System.out.println(ans + 1);
    }
}