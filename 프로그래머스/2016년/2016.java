package com.company;
import java.util.Arrays;
class Solution {
    public String[] day ={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    public int[] month ={31,29,31,30,31,30,31,31,30,31,30,31};
    public String solution(int a, int b) {
        String answer = "";
        int totalday = 0;
        for(int i=0; i<a-1;i++)
            totalday += month[i];
        totalday += b;
        int dayindex = (totalday+2)%7;
        answer = day[dayindex];
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();

    }
}
