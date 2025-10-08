
import java.util.*;

class Solution {
    
    static final int N = 2501;
    static final String BLANK = "";
    String[] data;
    int[] parent;
    List<String> ret;
    
    private int convert(int x, int y) {
        x--;
        y--;
        return 50 * x + y;
    }
    
    private void union(int a, int b) {
        a = find(a);
        b = find(b);
        parent[Math.max(a, b)] = Math.min(a, b);
    }
    
    private int find(int a) {
        if (parent[a] == a)
            return a;   
        return parent[a] = find(parent[a]);
    }
    
    private void init() {
        data = new String[N];
        parent = new int[N];
        ret = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            parent[i] = i;
            data[i] = BLANK;
        }
    }
    
    public String[] solution(String[] commands) {
        init();
        for (String command : commands) {
            String[] param = command.split(" ");
            if ("UPDATE".equals(param[0])) {
                if (param.length == 3) {
                    String val1 = param[1];
                    String val2 = param[2];
                    for (int i = 0; i < N; i++) {
                        if (val1.equals(data[i]))
                            data[i] = val2;
                    }
                }   
                else if (param.length == 4) {
                    int r1 = Integer.parseInt(param[1]);
                    int c1 = Integer.parseInt(param[2]);
                    int pk = find(convert(r1, c1));
                    String val = param[3];
                    
                    data[pk] = val;
                }   
            }
            else if ("MERGE".equals(param[0])) {
                int r1 = Integer.parseInt(param[1]);
                int c1 = Integer.parseInt(param[2]);
                int pk1 = find(convert(r1, c1));
                
                int r2 = Integer.parseInt(param[3]);
                int c2 = Integer.parseInt(param[4]);                
                int pk2 = find(convert(r2, c2)); 
                
                if (pk1 == pk2) continue;
                
                String val = BLANK.equals(data[pk1]) ? data[pk2] : data[pk1];
                data[pk1] = BLANK;
                data[pk2] = BLANK;
                union(pk1, pk2);
                data[parent[pk1]] = val;
            }
            else if ("UNMERGE".equals(param[0])) {
                int r1 = Integer.parseInt(param[1]);
                int c1 = Integer.parseInt(param[2]);
                int pk = find(convert(r1, c1));
                String val = data[pk];
                
                Set<Integer> set = new HashSet<>();
                for (int i = 0; i < N; i++) {
                    if (find(i) == pk) set.add(i);
                }
                for (int i : set) {
                    parent[i] = i;
                    data[i] = BLANK;
                }                
                
                data[convert(r1, c1)] = val;
            }
            else if ("PRINT".equals(param[0])) {
                int r1 = Integer.parseInt(param[1]);
                int c1 = Integer.parseInt(param[2]);
                int pk = find(convert(r1, c1));
            
                ret.add(data[pk]);
            }
        }
        
        String[] answer = new String[ret.size()];
        for (int i = 0; i < ret.size(); i++) {
            if (BLANK.equals(ret.get(i))) 
                answer[i] = "EMPTY";
            else
                answer[i] = ret.get(i);
        }
        return answer;
    }
}