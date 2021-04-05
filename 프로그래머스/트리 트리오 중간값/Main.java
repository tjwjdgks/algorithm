package com.company;
import java.util.*;
class Solution {
    public int solution(int n, int[][] edges) {
        ArrayList <Integer> [] list = new ArrayList[n+1];
        for (int i = 1; i <= n; i++) {
            list[i] = new ArrayList<Integer>();
        }
        for(int [] e : edges) {
            list[e[0]].add(e[1]);
            list[e[1]].add(e[0]);
        }

        int [] result = bfs(list, 1, n);
        int s = 1, max = 0, cnt = 0;
        for (int i = 2; i <= n; i++) {
            if(result[i] > result[s]) s = i;
        }
        result = bfs(list, s, n);
        s = 1;
        for (int i = 1; i <= n; i++) {
            if(result[i] > result[s]) s = i;
        }
        for(int i : result) max = Math.max(max, i);
        for(int i : result) if(max == i) cnt++;
        if(cnt >= 2) return max;
        max = 0; cnt = 0;
        result = bfs(list, s, n);
        for(int i : result) max = Math.max(max, i);
        for(int i : result) if(max==i) cnt++;
        if(cnt >= 2) return max;
        return max-1;
    }
    private static int [] bfs(ArrayList<Integer>[] list, int s, int n) {
        boolean [] visit = new boolean [n+1];
        int [] dist = new int [n+1];
        LinkedList<Integer> qu = new LinkedList<Integer>();
        qu.add(s);
        visit[s] = true;

        while(!qu.isEmpty()) {
            int num = qu.poll();
            for(int i : list [num]) {
                if(i == num || visit[i]) continue;
                visit[i] = true;
                qu.add(i);
                dist[i] = dist[num] + 1;
            }
        }
        return dist;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
        a.solution(4,new int[][]{{1,2},{2,3},{3,4}}	);
    }
}
