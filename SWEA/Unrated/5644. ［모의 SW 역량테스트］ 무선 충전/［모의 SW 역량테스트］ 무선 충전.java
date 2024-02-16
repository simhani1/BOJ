import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
/**
 * @author
 * 심종한
 * @date
 * 2024-02-15
 * @link
 * https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
 * https://drive.google.com/file/d/1pT4yBoYly3jT-d8NybtOBelVyfrYY7Bb/view?usp=sharing
 * @keyword_solution
 * 시간에 따라 변하는 위치를 갱신
 * 위치를 갱신할 때 마다 획득 가능한 에너지의 총합 구하기
 *
 * [1] A, B의 BC가 서로 다른 경우
 *      aPow + bPow
 * [2] A, B의 BC가 동일한 경우
 *      [2-1] 하나만 겹친다면
 *          반띵 -> but 총합을 구하므로 BC에서 충전 가능한 양과 동일
 *      [2-2]
 *          제일 많이 충전할 수 있는 값 2개를 선택
 *
 * [주의사항]
 * 문제에서 가로가 X, 세로가 Y축
 * @input
 * M(시간) <= 100
 * A(BC의 개수) <= 8
 * @output
 * 모든 사용자 충전량 합의 최댓값
 * @time_complex
 * O(T * M * A * A) = 50 * 100 * 8 * 8
 * @perf
 * 메모리: 20,464kb, 시간: 134ms
 */
 
public class Solution {
 
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int T, M, A;
    private static int[] rootA = new int[110];
    private static int[] rootB = new int[110];
    private static int[][] bc = new int[8][4];
    private static int[] dx = {0, 0, 1, 0, -1};
    private static int[] dy = {0, -1, 0, 1, 0};
 
    public static void main(String[] args) throws Exception {
        T = Integer.parseInt(br.readLine());
        for (int t = 1; t <= T; t++) {
            st = new StringTokenizer(br.readLine());
            M = Integer.parseInt(st.nextToken());
            A = Integer.parseInt(st.nextToken());
            /* A 경로 입력 */
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= M; i++) {
                rootA[i] = Integer.parseInt(st.nextToken());
            }
            /* B 경로 입력 */
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= M; i++) {
                rootB[i] = Integer.parseInt(st.nextToken());
            }
            /* Battery Charger 정보 입력 */
            for (int i = 0; i < A; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < 4; j++) {
                    bc[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            sb.append("#")
                    .append(t)
                    .append(" ")
                    .append(solve())
                    .append("\n");
        }
        System.out.println(sb.toString());
    }
 
    private static int solve() {
        int ans = 0;
        int aNowX = 1, aNowY = 1;
        int bNowX = 10, bNowY = 10;
        /* 시간대 별로 계산 진행 */
        for (int t = 0; t <= M; t++) {
            /* A 위치 변경 */
            aNowX += dx[rootA[t]];
            aNowY += dy[rootA[t]];
            /* B 위치 변경 */
            bNowX += dx[rootB[t]];
            bNowY += dy[rootB[t]];
            /* t 시간에 A, B 위치에서 충전 가능한 모든 경우의 수를 탐색,  총합의 최댓값 찾기 */
            int maxPow = 0;
            for (int i = 0; i < A; i++) {
                for (int j = 0; j < A; j++) {
                    int tmp = 0;
                    int aPow = calc(aNowX, aNowY, i);
                    int bPow = calc(bNowX, bNowY, j);
                    /* 다른 충전소 */
                    if (i != j) {
                        tmp += (aPow + bPow);
                    } else {
                        tmp += Math.max(aPow, bPow);
                    }
                    /* 최댓값 갱신 */
                    maxPow = Math.max(maxPow, tmp);
                }
            }
            /* 총합에 추가하기 */
            ans += maxPow;
        }
        return ans;
    }
 
    private static int calc(int x, int y, int idx) {
        int bcX = bc[idx][0];
        int bcY = bc[idx][1];
        int c = bc[idx][2];
        int p = bc[idx][3];
        /* 충전 가능 */
        if (Math.abs(x - bcX) + Math.abs(y - bcY) <= c) {
            return p;
        }
        /* 충전 불가능 */
        return 0;
    }
}