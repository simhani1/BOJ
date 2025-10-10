import java.util.*;

class Solution {
    
    int lenDelivery, lenPickup;
    
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long ans = 0L;
        lenDelivery = lenPickup = n;
        while (!(lenDelivery == 0 && lenPickup == 0)) {
            while (lenDelivery > 0 && deliveries[lenDelivery - 1] == 0) {
                lenDelivery--;
            }
            while (lenPickup > 0 && pickups[lenPickup - 1] == 0) {
                lenPickup--;
            }
            ans += Math.max(lenDelivery, lenPickup) * 2;
            lenDelivery = update(deliveries, lenDelivery, cap);
            lenPickup = update(pickups, lenPickup, cap);
        }
        return ans;
    }
    
    public int update(int[] arr, int len, int cap) {
        while (len > 0) {
            if (arr[len - 1] > cap) {
                arr[len - 1] -= cap;
                break;
            } else {
                cap -= arr[len - 1];
                len--;
            }
        }
        return len;
    }
}