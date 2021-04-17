package com.company;
import java.util.*;
class Solution {
    public int[] solution(String[] operations) {
        int[] answer = new int[2];
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        PriorityQueue<Integer> rpq = new PriorityQueue<>(Collections.reverseOrder());
        for(int i=0; i<operations.length;i++){
            String[] tarr = operations[i].split(" ");
            if(tarr[0].equals("I")){
                pq.add(Integer.parseInt(tarr[1]));
                rpq.add(Integer.parseInt(tarr[1]));
            }
            else{
                if (pq.isEmpty()) continue;
                if(Integer.parseInt(tarr[1]) == 1){
                    int maxnum = rpq.poll();
                    pq.remove(maxnum);
                }
                else{
                    int minnum = pq.poll();
                    rpq.remove(minnum);
                }
            }
        }
        if(pq.isEmpty()){
            answer[0] =0;
            answer[1] = 0;
        }
        else{
            answer[0] = rpq.poll();
            answer[1] = pq.poll();
        }
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
       // a.solution(4,new int[][]{{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}}	);
    }
}
