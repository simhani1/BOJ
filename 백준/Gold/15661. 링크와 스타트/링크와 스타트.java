import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N;
    static int ans = Integer.MAX_VALUE;
    static int[][] arr;
    static boolean[] visited;
    static boolean[] team;

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        arr = new int[N + 1][N + 1];
        visited = new boolean[N + 1];
        team = new boolean[N + 1];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for (int i = 0; i < N; i++) {
            team[i] = true;
            solve(i, 1);
            team[i] = false;
        }
        System.out.println(ans);
    }

    private static void solve(int idx, int cnt) {
        if (cnt <= N / 2) {
            int aStat = calcATeamStat();
            int bStat = calcBTeamStat();
            ans = Math.min(ans, Math.abs(aStat - bStat));
            for (int i = idx + 1; i < N; i++) {
                if (!team[i]) {
                    team[i] = true;
                    solve(i, cnt + 1);
                    team[i] = false;
                }
            }
        }
    }

    private static int calcBTeamStat() {
        int tmp = 0;
        List<Integer> members = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if (!team[i]) {
                members.add(i);
            }
        }
        for (int from : members) {
            for (int to : members) {
                if (from != to) {
                    tmp += arr[from][to];
                }
            }
        }
        return tmp;
    }

    private static int calcATeamStat() {
        int tmp = 0;
        List<Integer> members = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            if (team[i]) {
                members.add(i);
            }
        }
        for (int from : members) {
            for (int to : members) {
                if (from != to) {
                    tmp += arr[from][to];
                }
            }
        }
        return tmp;
    }
}