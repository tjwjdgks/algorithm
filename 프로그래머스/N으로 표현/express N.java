package com.company;
class Solution {
    public int answer =987654321;
    public int solution(int N, int number) {
        dfs(N,number,0,0);
        if(answer >8) return -1;
        else return answer;
    }
    public void dfs(int n, int number,int idx, int sum) {
        if (idx > 8) return;
        if (sum == number) {
            answer = Math.min(answer, idx);
        }
        int temp = 0;
        for (int i = 0; i < 8; i++) {
            temp = temp * 10 + n;
            dfs(n, number, idx + i + 1, sum + temp);
            dfs(n, number, idx + i + 1, sum - temp);
            dfs(n, number, idx + i + 1, sum / temp);
            dfs(n, number, idx + i + 1, sum * temp);
        }
    }
}
public class Main {

    public static void main(String[] args) {
        Solution a = new Solution();
    }
}
