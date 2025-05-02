import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeMap;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N;

    static class Node {

        Map<String, Node> child;

        public Node() {
            this.child = new TreeMap<>();
        }

        public void add(List<String> list, int idx) {
            if (idx == list.size()) {
                return;
            }
            String now = list.get(idx);
            child.putIfAbsent(now, new Node());
            child.get(now).add(list, idx + 1);
        }

        public void print(int idx) {
            for (String now : child.keySet()) {
                for (int i = 0; i < idx; i++) {
                    sb.append("--");
                }
                sb.append(now).append("\n");
                child.get(now).print(idx + 1);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        Node root = new Node();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int M = Integer.parseInt(st.nextToken());
            List<String> list = new ArrayList<>();
            for (int j = 0; j < M; j++) {
                list.add(st.nextToken());
            }
            root.add(list, 0);
        }
        root.print(0);
        System.out.println(sb);
    }
}