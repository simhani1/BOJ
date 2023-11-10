import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;


public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static List<Integer> ans = new ArrayList<>();
    static int[] arr = new int[101];
    static boolean[] visited = new boolean[101];

    public static void main(String[] args) throws IOException {
        int N = Integer.parseInt(br.readLine());
        for (int i = 1; i <= N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        for (int i = 1; i <= N; i++) {
            dfs(i, i);
        }
        Collections.sort(ans);
        System.out.println(ans.size());
        for (Integer num : ans) {
            System.out.println(num);
        }
    }

    private static void dfs(int now, int start) {
        if (visited[now] && now == start) {
            ans.add(now);
            return;
        }
        if (visited[now])
            return;
        visited[now] = true;
        dfs(arr[now], start);
        visited[now] = false;
    }
}

