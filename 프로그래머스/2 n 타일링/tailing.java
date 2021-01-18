package com.company;
class Solution {
    public int solution(int n) {
        int []cashe = new int[n];
        cashe[0] =1;
        cashe[1] = 2;
        for(int i=2;i<n;i++){
            cashe[i] = (cashe[i-1] + cashe[i-2])%1000000007;
        }
        return cashe[n-1];
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
    }
}
