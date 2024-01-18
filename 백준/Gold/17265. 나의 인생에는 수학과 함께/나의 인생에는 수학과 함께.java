import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static int N;
    static int K;
    static int maxAns = Integer.MIN_VALUE;
    static int minAns = Integer.MAX_VALUE;
    static char[][] arr = new char[5][5];
    static int[] dx = {0, 1};
    static int[] dy = {1, 0};

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                arr[i][j] = String.valueOf(st.nextToken()).charAt(0);
            }
        }

        dfs(0, 0, "");

        // ans
        System.out.println(maxAns + " " + minAns);
    }

    static void dfs(int nowX, int nowY, String result) {
        String tmpResult = new String(result + arr[nowX][nowY]);
        if (nowX == N - 1 && nowY == N - 1) {
            // 계산 결과
            int pSum = 0;
            for (int i = 0; i < tmpResult.length(); i++) {
                if (i == 1) {
                    if (tmpResult.charAt(i) == '+') {
                        pSum += ((tmpResult.charAt(i - 1) - '0') +( tmpResult.charAt(i + 1) - '0'));
                    } else if (tmpResult.charAt(i) == '-') {
                        pSum += ((tmpResult.charAt(i - 1) - '0') - (tmpResult.charAt(i + 1) - '0'));
                    } else if (tmpResult.charAt(i) == '*') {
                        pSum += ((tmpResult.charAt(i - 1) - '0') * (tmpResult.charAt(i + 1) - '0'));
                    }
                } else if (1 < i && i < tmpResult.length() - 1) {
                    if (tmpResult.charAt(i) == '+') {
                        pSum += (tmpResult.charAt(i + 1) - '0');
                    } else if (tmpResult.charAt(i) == '-') {
                        pSum -= (tmpResult.charAt(i + 1) - '0');
                    } else if (tmpResult.charAt(i) == '*') {
                        pSum *= (tmpResult.charAt(i + 1) - '0');
                    }
                }

            }
            maxAns = Math.max(maxAns, pSum);
            minAns = Math.min(minAns, pSum);
            return;
        }
        for (int i = 0; i < 2; i++) {
            int nextX = nowX + dx[i];
            int nextY = nowY + dy[i];
            if (0 > nextX || nextX >= N || 0 > nextY || nextY >= N) {
                continue;
            }
            dfs(nextX, nextY, tmpResult);
        }
    }
}