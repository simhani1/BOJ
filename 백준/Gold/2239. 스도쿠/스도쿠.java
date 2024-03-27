import javax.sound.sampled.EnumControl;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringBuilder sb = new StringBuilder();
    private static StringTokenizer st;
    private static int[][] arr = new int[9][9];

    public static void main(String[] args) throws IOException {
        int cnt = 0;
        for (int i = 0; i < 9; i++) {
            String str = br.readLine();
            for (int j = 0; j < 9; j++) {
                arr[i][j] = str.charAt(j) - '0';
                if (arr[i][j] == 0) {
                    cnt++;
                }
            }
        }
        solve(0, cnt);
    }

    private static void solve(int cnt, int goal) {
        if (cnt == goal) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    sb.append(arr[i][j]);
                }
                sb.append("\n");
            }
            System.out.println(sb.toString());
            System.exit(0);
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (arr[i][j] != 0) {
                    continue;
                }
                int k;
                for (k = 1; k <= 9; k++) {
                    if (notInGaro(i, j, k) && notInSaero(i, j, k) && notInSquare(i, j, k)) {
                        arr[i][j] = k;
                        solve(cnt + 1, goal);
                        arr[i][j] = 0;
                    }
                }
                if (k == 10) {
                    return;
                }
            }
        }
    }

    private static boolean notInSquare(int x, int y, int num) {
        int beginX = (x / 3) * 3;
        int beginY = (y / 3) * 3;
        for (int i = beginX; i < beginX + 3; i++) {
            for (int j = beginY; j < beginY + 3; j++) {
                if (arr[i][j] == num) {
                    return false;
                }
            }
        }
        return true;
   }

    private static boolean notInSaero(int x, int y, int num) {
        for (int i = 0; i < 9; i++) {
            if (arr[i][y] == num) {
                return false;
            }
        }
        return true;
    }

    private static boolean notInGaro(int x, int y, int num) {
        for (int j = 0; j < 9; j++) {
            if (arr[x][j] == num) {
                return false;
            }
        }
        return true;
    }
}