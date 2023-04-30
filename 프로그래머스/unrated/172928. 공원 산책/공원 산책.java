class Solution {
        
    public int[] solution(String[] park, String[] routes) {
        int[] answer = new int[2];
        
        int row = park.length;
        int col = park[0].length();
        char[][] arr = new char[row][col];
        int nowX = 0;
        int nowY = 0;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                arr[i][j] = park[i].charAt(j);
                if(arr[i][j] == 'S'){
                    nowX = i;
                    nowY = j;
                }
            }
        }
        
        for (int i = 0; i < routes.length; i++) {
            char cmd = routes[i].charAt(0);
            int cnt = (int) (routes[i].charAt(2) - '0');
            boolean skip = false;
            if (cmd == 'N') {
                if (0 <= nowX - cnt) {
                    for (int j = 1; j <= cnt; j++) {
                        if (arr[nowX - j][nowY] == 'X') {
                            skip = true;
                            break;
                        }
                    }
                    if(!skip)
                        nowX -= cnt;
                }
            } else if (cmd == 'E') {
                if (nowY + cnt < col) {
                    for (int j = 1; j <= cnt; j++) {
                        if (arr[nowX][nowY + j] == 'X') {
                            skip = true;
                            break;
                        }
                    }
                    if(!skip)
                        nowY += cnt;
                }
            } else if (cmd == 'S') {
                if (nowX + cnt < row) {
                    for (int j = 1; j <= cnt; j++) {
                        if (arr[nowX + j][nowY] == 'X') {
                            skip = true;
                            break;
                        }
                    }
                    if(!skip)
                        nowX += cnt;
                }
            } else if (cmd == 'W') {
                if (0 <= nowY - cnt) {
                    for (int j = 1; j <= cnt; j++) {
                        if (arr[nowX][nowY - j] == 'X') {
                            skip = true;
                            break;
                        }
                    }
                    if(!skip)
                        nowY -= cnt;
                }
            }
        }
        answer[0] = nowX;
        answer[1] = nowY;
        return answer;
    }
}