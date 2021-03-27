package com.company;
import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String,Integer> hashMap = new HashMap<>();
        for(int i=0; i<clothes.length;i++){
            hashMap.put(clothes[i][1],hashMap.getOrDefault(clothes[i][1],0)+1);
        }
        int []arr= new int[hashMap.size()];
        int idx =0;
        for(Integer value : hashMap.values()){
            arr[idx++] = value;
        }
        for(int i=0; i<arr.length;i++)
            answer *= arr[i]+1;
        answer -=1;
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
        a.solution(new String[][]{{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}});
    }
}
