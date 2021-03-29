package com.company;
import java.util.*;

class Solution {
    public int []arr;
    public int count =0;
    public int targetn = 0;
    public void dfs(int idx, int targetnum){
        if(idx == arr.length){
            if(targetn == targetnum)
                count++;
            return;
        }
        dfs(idx+1,targetnum+arr[idx]);
        dfs(idx+1,targetnum-arr[idx]);
        return;
    }
    public int solution(int[] numbers, int target) {
        int answer = 0;
        arr = new int[numbers.length];
        for(int i=0; i<numbers.length;i++){
            arr[i] = numbers[i];
        }
        targetn = target;
        dfs(0,0);
        answer = count;
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
    }
}
