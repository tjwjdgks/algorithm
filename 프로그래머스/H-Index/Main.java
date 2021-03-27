package com.company;
import java.util.Arrays;
import java.util.Collections;

class Solution {
    public int solution(int[] citations) {
        int answer = 0;
        citations = Arrays.stream(citations).boxed().sorted(Collections.reverseOrder()).mapToInt(Integer::intValue).toArray();
        for(int i=0; i<citations.length;i++){
            if(i+1 > citations[i]){
                return i;
            }
        }
        return citations.length;
    }
}
public class Main {
    public static void main(String[] args) {


    }
}
