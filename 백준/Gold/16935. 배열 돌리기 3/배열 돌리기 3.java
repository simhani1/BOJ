import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int N, M, R;
    private static int[][] arr;

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        R = Integer.parseInt(st.nextToken());
        arr = new int[N][M];
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < R; i++) {
            int op = Integer.parseInt(st.nextToken());
            switch (op) {
                case 1:
                    arr = spin1();
                    break;
                case 2:
                    arr = spin2();
                    break;
                case 3:
                    arr = spin3();
                    break;
                case 4:
                    arr = spin4();
                    break;
                case 5:
                    arr = spin5();
                    break;
                case 6:
                    arr = spin6();
                    break;
            }
        }
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                sb.append(arr[i][j])
                        .append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }

    private static int[][] spin1() {
        int n = arr.length;
        int m = arr[0].length;
        int[][] tmp = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j] = arr[n - 1 - i][j];
            }
        }
        return tmp;
    }

    private static int[][] spin2() {
        int n = arr.length;
        int m = arr[0].length;
        int[][] tmp = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j] = arr[i][m - 1 - j];
            }
        }
        return tmp;
    }

    private static int[][] spin3() {
        int n = arr.length;
        int m = arr[0].length;
        int[][] tmp = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[i][j] = arr[n - 1 - j][i];
            }
        }
        return tmp;
    }

    private static int[][] spin4() {
        int n = arr.length;
        int m = arr[0].length;
        int[][] tmp = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                tmp[i][j] = arr[j][m - 1 - i];
            }
        }
        return tmp;
    }

    private static int[][] spin5() {
        int n = arr.length;
        int m = arr[0].length;
        int[][] tmp = new int[n][m];
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                tmp[i][j] = arr[i + n / 2][j];
            }
            for (int j = m / 2; j < m; j++) {
                tmp[i][j] = arr[i][j - m / 2];
            }
        }
        for (int i = n / 2; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                tmp[i][j] = arr[i][j + m / 2];
            }
            for (int j = m / 2; j < m; j++) {
                tmp[i][j] = arr[i - n / 2][j];
            }
        }
        return tmp;
    }

    private static int[][] spin6() {
        int n = arr.length;
        int m = arr[0].length;
        int[][] tmp = new int[n][m];
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < m / 2; j++) {
                tmp[i][j] = arr[i][j + m / 2];
            }
            for (int j = m / 2; j < m; j++) {
                tmp[i][j] = arr[i + n / 2][j];
            }
        }
        for (int i = n / 2; i < n; i++) {
            for (int j = 0; j < m / 2; j++) {
                tmp[i][j] = arr[i - n / 2][j];
            }
            for (int j = m / 2; j < m; j++) {
                tmp[i][j] = arr[i][j - m / 2];
            }
        }
        return tmp;
    }
}
