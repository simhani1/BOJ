import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {

    private static BufferedReader br;
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int P, S, ans = 0;
    private static String dna;
    private static Map<Character, Integer> arr = new HashMap<>();

    public static void main(String[] args) throws Exception {
        br = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer(br.readLine());
        S = Integer.parseInt(st.nextToken());
        P = Integer.parseInt(st.nextToken());
        dna = br.readLine();
        st = new StringTokenizer(br.readLine());

        arr.put('A', Integer.parseInt(st.nextToken()));
        arr.put('C', Integer.parseInt(st.nextToken()));
        arr.put('G', Integer.parseInt(st.nextToken()));
        arr.put('T', Integer.parseInt(st.nextToken()));

        solve();
        System.out.println(ans);
    }

    private static void solve() {
        int l = 0, r = P - 1;
        int sum = 0;
        int[] cnt = new int[4];
        Map<Character, Integer> m = new HashMap<>();
        m.put('A', 0);
        m.put('C', 0);
        m.put('G', 0);
        m.put('T', 0);
        for (int i = l; i <= r; i++) {
            m.put(dna.charAt(i), m.get(dna.charAt(i)) + 1);
        }
        if (isValid(m)) {
            ans++;
        }
        while (true) {
            r++;
            if (r == S) {
                return;
            }
            m.put(dna.charAt(r), m.get(dna.charAt(r)) + 1);
            m.put(dna.charAt(l), m.get(dna.charAt(l)) - 1);
            l++;
            if (isValid(m)) {
                ans++;
            }
        }
    }

    private static boolean isValid(Map<Character, Integer> m) {
        char[] c = {'A', 'C', 'G', 'T'};
        for (int i = 0; i < 4; i++) {
            if (m.get(c[i]) < arr.get(c[i])) {
                return false;
            }
        }
        return true;
    }
}