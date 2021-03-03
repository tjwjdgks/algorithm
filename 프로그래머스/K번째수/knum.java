package com.company;
import java.util.Arrays;
import java.util.ArrayList;
import java.util.List;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i=0; i<commands.length;i++){
            int[] temparry = Arrays.copyOfRange(array,commands[i][0]-1,commands[i][1]);
            Arrays.sort(temparry);
            arr.add(temparry[commands[i][2]-1]);
        }
        int []answer = arr.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();

    }
}
