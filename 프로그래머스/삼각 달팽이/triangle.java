package com.company;
    class Solution {
        public int[] solution(int n) {
            int [][] arry = new int[n][n];
            int x=0;
            int y=-1;
            // 0(아래, 오른 대각)
            int flag = 0;
            int curnum =1;
            for(int i=n; i>=1;i--){
                for(int j=1;j<=i;j++){
                    if(flag%3==0){
                        y++;
                        arry[y][x] = curnum++;
                    }
                    else if(flag%3==1){
                        x++;
                        arry[y][x] = curnum++;
                    }
                    else{
                        x--;
                        y--;
                        arry[y][x] = curnum++;
                    }
                }
                flag++;
            }
            int [] answer = new int[--curnum];
            int idx =0;
            for(int i=0; i<n;i++){
                for(int j=0; j<=i; j++){
                    answer[idx++]=arry[i][j];
                }
            }
            return answer;
        }
    }
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
        a.solution(4);

    }
}
