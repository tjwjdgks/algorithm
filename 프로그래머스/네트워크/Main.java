package com.company;
import java.util.*;

class Solution {
    public int totalcount =0;
    public int [][] arr;
    public boolean [] check;
    public void dfs(int n, int count){
        if(check[n] == true)
            return;
        check[n] = true;
        if(count == 0)
            totalcount++;
        for(int i=0;i<arr[n].length;i++){
            if(arr[n][i] == 1 && !check[i])
                dfs(i,count+1);
        }
    }
    public int solution(int n, int[][] computers) {
        int answer = 0;
        check = new boolean[n];
        arr= new int[computers.length][computers[0].length];
        for(int i=0; i<arr.length;i++){
            for(int j=0; j<arr[0].length;j++)
                arr[i][j] = computers[i][j];
        }
        for(int i=0;i<n;i++){
            dfs(i,0);
        }
        answer = totalcount;
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
    }
}
