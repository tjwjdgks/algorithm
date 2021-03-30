package com.company;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Arrays;
import java.util.Collections;
class Solution {
    public int solution(int n, int[][] edge) {
        int answer = 0;
        boolean [][] checkedge = new boolean[n][n];
        for(int i=0; i<edge.length;i++){
            if(edge[i][0] != edge[i][1]){
                checkedge[edge[i][0]-1][edge[i][1]-1] = true;
                checkedge[edge[i][1]-1][edge[i][0]-1] = true;
            }
        }
        boolean [] checknode = new boolean[n];
        int[] distance = new int[n];
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        checknode[0] = true;
        int maxnum = 0;
        while(!q.isEmpty()){
            int curnodeidx = q.peek();
            q.poll();
            for(int i=0; i<n;i++){
                if(checkedge[curnodeidx][i] && !checknode[i]){
                    q.add(i);
                    checknode[i] = true;
                    distance[i] = distance[curnodeidx]+1;
                    maxnum = distance[i];
                }
            }
        }
        for(int i=0;i<distance.length;i++){
            if(maxnum == distance[i])
                answer++;
        }
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
        a.solution(	6, new int[][]{{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}});
    }
}
