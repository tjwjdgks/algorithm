package com.company;
import java.util.*;

class Solution {
    public HashMap<String,Integer>      map = new HashMap<>();
    public void backtracking(String s,String target,int count,int idx){
        if(target.length() == count){
            map.put(target,map.getOrDefault(target,0)+1);
            return;
        }
        for(int i=idx;i<s.length();i++){
            backtracking(s,target+s.charAt(i),count,i+1);
        }
    }
    public String[] solution(String[] orders, int[] course) {
        for(int i=0; i<orders.length;i++){
            char[] carr = orders[i].toCharArray();
            Arrays.sort(carr);
            String sort_arr = new String(carr);
            for(int j=0; j<course.length; j++){
                if(sort_arr.length()<course[j]) continue;
                backtracking(sort_arr,"",course[j],0);
            }
        }
        ArrayList<String> arr = new ArrayList<>();
        for(Map.Entry<String,Integer> m : map.entrySet()){
            if(m.getValue()>=2)
                arr.add(m.getKey());
        }
        Collections.sort(arr);
        String[] answer = arr.stream().toArray(String[]::new);
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
       a.solution(new String[]{"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"},new int[]{2,3,4});
    }
}
