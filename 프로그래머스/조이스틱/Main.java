package com.company;
class Solution {
    public int solution(String name) {
        int answer = 0;
        char[] carr = new char[name.length()];
        char[] narr = name.toCharArray();
        for(int i=0;i<name.length();i++)
            carr[i] = 'A';
        boolean check = true;
        int start = 0;
        while(check){
            int idx = -1;
            for(int i=0; i<narr.length;i++){
                int left = start - i;
                if(left<0)
                    left = left + narr.length;
                int right = start + i;
                if(right>narr.length-1)
                    right = right - narr.length;
                if(carr[left] != narr[left]){
                    idx = left;
                    answer += i;
                    break;
                }
                else if(carr[right] != narr[right]){
                    idx = right;
                    answer +=i;
                    break;
                }
            }
            if(idx == -1) break;
            answer += Math.min(narr[idx]-'A','Z'-narr[idx]+1);
            carr[idx] = narr[idx];
            start = idx;
        }
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
        a.solution("JAN");
    }
}
