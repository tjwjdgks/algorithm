package com.company;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n;
        Arrays.sort(lost);
        HashSet<Integer> set = new HashSet<>();
        for(int i=0; i<reserve.length;i++){
            set.add(reserve[i]);
        }
        for(int i=0; i<lost.length;i++){
            if(set.contains(lost[i])){
                set.remove(lost[i]);
            }
            else if(set.contains(lost[i]-1)){
                set.remove(lost[i]-1);
            }
            else if(i!=lost.length-1 && set.contains(lost[i]+1) && lost[i+1] != lost[i]+1){
                set.remove(lost[i]+1);
            }
            else
                answer--;
        }
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();

    }
}
