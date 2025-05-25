import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int N;

    static class Trie {
        Trie[] arr;
        int cnt;

        public Trie() {
            this.arr = new Trie[26];
            this.cnt = 0;
        }

        public void insert(String word, int len, boolean flag) {
            if (word.length() == len) {
                cnt++;
                if (!flag) {
                    sb.append(word).append(cnt == 1 ? "" : cnt).append("\n");
                }
                return;
            }
            int idx = word.charAt(len) - 'a';
            if (arr[idx] == null) {
                arr[idx] = new Trie();
                if (!flag) {
                    flag = true;
                    sb.append(word.substring(0, len + 1)).append("\n");
                }
            }
            arr[idx].insert(word, len + 1, flag);
        }
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        Trie root = new Trie();
        for (int i = 0; i < N; i++) {
            String str = br.readLine();
            root.insert(str, 0, false);
        }
        System.out.println(sb);
    }
}
