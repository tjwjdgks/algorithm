package com.company;
import java.util.*;
class Solution {
    public int [] check;
    public int find(int a){
        if(a == check[a]) return a;
        return check[a] = find(check[a]);
    }
    public int solution(int n, int[][] costs) {
        int answer = 0;
        check = new int[n];
        for(int i=0; i<check.length;i++){
            check[i] = i;
        }
        Arrays.sort(costs, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[2] - o2[2];
            }
        });
        int count = 0 ;
        int idx = 0;
        while(count<n-1){
            int firsttemp = find(costs[idx][0]);
            int secondtemp = find(costs[idx][1]);
            if(firsttemp != secondtemp){
                count++;
                answer += costs[idx][2];
                if(firsttemp>secondtemp){
                    check[firsttemp] = secondtemp;
                }
                else{
                    check[secondtemp] = firsttemp;
                }
            }
            idx++;
        }
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
        a.solution(4,new int[][]{{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}}	);
    }
}
