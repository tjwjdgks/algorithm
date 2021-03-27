package com.company;
import java.util.*;

class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2];
        // 세로
        for(int i=1; i<=Math.sqrt(yellow);i++){
            if(yellow%i==0){
                int row = yellow/i;
                if(brown == row*2+i*2+4){
                    //가로
                    answer[0] = row+2;
                    //세로
                    answer[1] = i+2;
                }
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
