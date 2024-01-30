import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.SortedSet;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static boolean[] visited = new boolean[51];

    public static void main(String[] args) throws Exception {
         br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        System.out.println(solve(str, 0));
    }

    private static int solve(String str, int idx) {
        Stack<Character> st = new Stack<>();
        int len = 0;
        for (int i = idx; i < str.length(); i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            if (str.charAt(i) == ')') {
                return st.size() + len;
            } else if (str.charAt(i) == '(') {
                len += ((st.peek() - '0') * solve(str, i + 1));
                st.pop();
            } else {
                st.push(str.charAt(i));
            }
        }
        return st.size() + len;
    }
}