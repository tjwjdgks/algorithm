package com.company;
import java.util.ArrayList;
import java.util.Queue;
import java.util.LinkedList;
class Areanum{
    int x,y;
    public Areanum(int y,int x){
        this.x= x;
        this.y= y;
    }
}
class Solution {
    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;
        int []dx = {0,1,0,-1};
        int []dy = {1,0,-1,0};
        Queue<Areanum> q = new LinkedList<>();
        boolean [][] check = new boolean[m][n];
        for(int i=0; i<m;i++){
            for(int j=0; j<n;j++){
                if(picture[i][j] !=0){
                    if(check[i][j] == false){
                        check[i][j] = true;
                        numberOfArea++;
                        int tempcount =0;
                        q.add(new Areanum(i,j));
                        while(!q.isEmpty()){
                            Areanum temp = q.poll();
                            tempcount++;
                            for(int k=0;k<4;k++){
                                int tempx = temp.x +dx[k];
                                int tempy = temp.y +dy[k];
                                if(tempx>=0&& tempx<n&& tempy>=0 && tempy<m && picture[tempy][tempx] == picture[i][j]){
                                    if(check[tempy][tempx]==false){
                                        check[tempy][tempx] = true;
                                        q.add(new Areanum(tempy,tempx));
                                    }
                                }
                            }
                        }
                        if(tempcount>maxSizeOfOneArea) maxSizeOfOneArea = tempcount;
                    }
                }
            }
        }
        int[] answer = new int[2];
        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }
}
public class Main {

    public static void main(String[] args) {
        Solution a = new Solution();
        int []c = a.solution(	6, 4, new int[][]{{1, 1, 1, 0}, {1, 2, 2, 0}, {1, 0, 0, 1},{0,0,0,1}, {0, 0, 0, 3}, {0, 0, 0, 3}});
    }
}
