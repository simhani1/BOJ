import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static StringTokenizer st;
    private static StringBuilder sb = new StringBuilder();
    private static int L, C;
    private static SortedSet<String> set = new TreeSet<>();
    private static int[] arr = new int[26];

    public static void main(String[] args) throws Exception {
        st = new StringTokenizer(br.readLine());
        L = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        char[] chars = br.readLine().replaceAll(" ", "").toCharArray();
        for (int i = 0; i < C; i++) {
            arr[chars[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) {
                arr[i]--;
                dfs(i, String.valueOf((char) (i + 'a')));
                arr[i]++;
            }
        }
        for (String s : set) {
            System.out.println(s);
        }
    }

    private static void dfs(int idx, String s) {
        if (s.length() == L) {
            int consonant = 0, vowel = 0;
            for (int i = 0; i < s.length(); i++) {
                switch (s.charAt(i)) {
                    case 'a':
                    case 'e':
                    case 'i':
                    case 'o':
                    case 'u':
                        consonant++;
                        break;
                    default:
                        vowel++;
                }
            }
            if (consonant >= 1 && vowel >= 2) {
                set.add(s);
            }
            return;
        }
        for (int i = idx + 1; i < 26; i++) {
            if (arr[i] != 0) {
                arr[i]--;
                dfs(i, s + String.valueOf((char) (i + 'a')));
                arr[i]++;
            }
        }
    }
}