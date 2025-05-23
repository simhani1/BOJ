import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();
    static int X;
    static String str;
    static Set<String> set = new HashSet<>();
    static List<String> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        X = Integer.parseInt(br.readLine());
        str = br.readLine();
        while (!set.contains(str)) {
            set.add(str);
            list.add(str);
            sb = new StringBuilder();
            int l = 0, r = str.length() - 1;
            if (str.length() % 2 == 0) {
                while (l < r) {
                    sb.append(str.charAt(l++));
                    sb.append(str.charAt(r--));
                }
            } else {
                while (l < r) {
                    sb.append(str.charAt(l++));
                    sb.append(str.charAt(r--));
                }
                sb.append(str.charAt(l));
            }
            str = sb.toString();
        }
        int cycle = list.size();
        if (cycle == 1) {
            System.out.println(list.get(0));
        } else {
            int idx = list.size() - (X % cycle);
            System.out.println(list.get(idx));
        }
    }
}
