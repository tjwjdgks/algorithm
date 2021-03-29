package com.company;
import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public int solution(int[][] routes) {
        int answer = 0;
        Arrays.sort(routes, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0]-o2[0];
            }
        });
        int sortpath = -30001;
        for(int i=0; i<routes.length;i++){
            if(routes[i][0]<=sortpath){
                sortpath = Math.min(sortpath,routes[i][1]);
            }
            else{
                answer++;
                sortpath = routes[i][1];
            }
        }
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
    }
}
