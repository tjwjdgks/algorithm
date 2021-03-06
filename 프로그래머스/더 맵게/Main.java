package com.company;
import java.util.Arrays;
import java.util.PriorityQueue;
class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=0; i<scoville.length;i++){
            pq.add(scoville[i]);
        }
        while(pq.peek()<=K){
            int first = pq.peek();
            pq.poll();
            if(pq.isEmpty()){
                answer = -1;
                break;
            }
            int second = pq.peek();
            pq.poll();
            int newnum = first + second*2;
            pq.add(newnum);
            answer++;
        }
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
    }
}
