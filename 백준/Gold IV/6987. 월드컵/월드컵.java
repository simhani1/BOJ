import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, ans;
    private static int[][] arr = new int[6][3];
    private static int[][] game = new int[6][3];
    private static int[][] result = {{0, 2}, {1, 1}, {2, 0}};
    private static int[][] league = {
            {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}
            , {1, 2}, {1, 3}, {1, 4}, {1, 5}
            , {2, 3}, {2, 4}, {2, 5}
            , {3, 4}, {3, 5}
            , {4, 5}};

    public static void main(String[] args) throws Exception {
        for (int t = 0; t < 4; t++) {
            ans = 0;
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    arr[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            solve(0);
            sb.append(ans)
                    .append(" ");
        }
        System.out.println(sb.toString());
    }

    private static void solve(int idx) {
        if (idx == 15) {
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    if (arr[i][j] != game[i][j]) {
                        return;
                    }
                }
            }
            ans = 1;
            return;
        }
        /* 경기 기록 */
        int teamA = league[idx][0];
        int teamB = league[idx][1];
        for (int i = 0; i < 3; i++) {
            game[teamA][result[i][0]]++;
            game[teamB][result[i][1]]++;
            solve(idx + 1);
            game[teamA][result[i][0]]--;
            game[teamB][result[i][1]]--;
        }
    }
}