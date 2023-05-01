import java.util.*;

class Solution {
    public int solution(String[][] book_time) {
        int[][] bookTime = new int[book_time.length][2];

        for (int i = 0; i < book_time.length; i++) {
            int startTime = Integer.parseInt(book_time[i][0].replace(":", ""));
            int endTime = Integer.parseInt(book_time[i][1].replace(":", ""));
            endTime += 10;
            if (endTime % 100 >= 60) {
                endTime += (100 - 60);  // 시간을 나타내는 백의 자리++ & 분 초기화
            }
            bookTime[i][0] = startTime;
            bookTime[i][1] = endTime;
        }

        Arrays.sort(bookTime, (a,b)->{
            if (a[0] > b[0]) {
                return 1;
            } else if (a[0] < b[0]) {
                return -1;
            } else {
                if (a[1] > b[1]) {
                    return 1;
                } else {
                    return -1;
                }
            }
        });

        PriorityQueue<Integer> room = new PriorityQueue<>();
        for (int[] timeArr : bookTime) {
            // 첫 예약인 경우
            if (room.size() == 0) {
                room.add(timeArr[1]);
                continue;
            }
            int firstRoom = room.peek();
            if (timeArr[0] >= firstRoom) {
                room.poll();
                room.add(timeArr[1]);
            } else {
                room.add(timeArr[1]);
            }
        }
        return room.size();
    }
}