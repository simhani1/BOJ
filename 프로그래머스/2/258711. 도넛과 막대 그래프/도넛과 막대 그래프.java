import java.util.*;

class Solution {
    
    int maxN = 1_000_000;
    int[] inDegree, outDegree;
    int[] answer;
    List<Integer>[] graph;
    Set<Integer> set;
    
    public int[] solution(int[][] edges) {
        answer = new int[4];
        inDegree = new int[maxN + 1];
        outDegree = new int[maxN + 1];
        set = new HashSet<>();
        for (int[] edge : edges) {
            int a = edge[0];
            int b = edge[1];
            inDegree[b]++;
            outDegree[a]++;
            set.add(a);
            set.add(b);
        }
        
        for (int node : set) {
            if (isRemoved(node)) answer[0] = node;
            else if (isEight(node)) answer[3]++;
            else if (isStick(node)) answer[2]++;
        }
        answer[1] = outDegree[answer[0]] - answer[2] - answer[3];
        return answer;
    }
    
    public boolean isRemoved(int num) {
        return inDegree[num] == 0 && outDegree[num] >= 2;
    }

    public boolean isEight(int num) {
        return inDegree[num] >= 2 && outDegree[num] >= 2;
    }  
    
    public boolean isStick(int num) {
        return inDegree[num] > 0 && outDegree[num] == 0;
    }  
    
}