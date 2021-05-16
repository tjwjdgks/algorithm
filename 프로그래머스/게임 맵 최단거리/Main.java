package com.company;

import java.util.*;
class Node{
    public int x,y, distance;
    public Node(int y, int x , int distance){
        this.x = x;
        this.y = y;
        this.distance = distance;
    }
}
class Solution {
    public int dy[] ={0,-1,0,1};
    public int dx[] ={1, 0,-1,0};
    public int solution(int[][] maps) {
        int answer = -1;
        int n = maps.length;
        int m = maps[0].length;
        boolean [][] maparr=  new boolean[n][m];
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(0,0,1));
        maparr[0][0] = true;
        while(!q.isEmpty()){
            Node temp = q.poll();
            if(temp.y == n-1 && temp.x == m-1){
                answer = temp.distance;
                break;
            }
            for(int i=0; i<4;i++){
                int tempy = temp.y + dy[i];
                int tempx = temp.x + dx[i];
                if(tempy>=0 && tempx>=0 && tempy<n && tempx < m && maparr[tempy][tempx] == false){
                    if(maps[tempy][tempx] == 1){
                        maparr[tempy][tempx] = true;
                        q.add(new Node(tempy,tempx,temp.distance+1));
                    }
                }
            }
        }
              
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {


    }
}
