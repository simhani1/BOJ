import java.util.*;

class Solution {
    int[] arr;
    public int solution(int[] elements) {
        arr = new int[1 + elements.length * 2];
        for (int i = 1; i <= elements.length; i++) {
            arr[i] = arr[i + elements.length] = elements[i - 1];
        }
        for (int i = 1; i < arr.length; i++) {
            arr[i] += arr[i - 1];
        }
        
        Set<Integer> set = new HashSet<>();
        for (int window = 0; window < elements.length; window++) {
            for (int i = 1; i <= elements.length; i++) {
                set.add(arr[i + window] - arr[i - 1]);
            }
        }
        return set.size();
    }
}