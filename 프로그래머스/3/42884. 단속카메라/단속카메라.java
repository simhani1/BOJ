import java.util.*;

class Solution {

    public int solution(int[][] routes) {
        Arrays.sort(routes, (o1, o2) -> {
            if (o1[0] == o2[0]) {
                return Integer.compare(o1[1], o2[1]);
            }
            return Integer.compare(o1[0], o2[0]);
        });
        int N = routes.length;     
        int ans = 1;
        int camera = routes[0][1];        
        for (int i = 1; i < N; i++) {
            if (routes[i][1] <= camera) {
                camera = routes[i][1];
            }
            else if (camera < routes[i][0]) {
                camera = routes[i][1];
                ans++;
            }
        }
        return ans;
    }
}