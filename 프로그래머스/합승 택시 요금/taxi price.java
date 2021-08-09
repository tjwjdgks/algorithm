import java.util.Arrays;


class Solution {
    public int solution(int n, int s, int a, int b, int[][] fares) {
        int answer = Integer.MAX_VALUE;
        int [][] arr= new int[n][n];
        for(int i=0;i<n;i++)
            Arrays.fill(arr[i],100_001*n);
        for(int i=0;i<n;i++)
            arr[i][i] = 0;
        for(int i=0;i<fares.length;i++){
            arr[fares[i][0]-1][fares[i][1]-1] = fares[i][2];
            arr[fares[i][1]-1][fares[i][0]-1] = fares[i][2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    arr[i][j] = Math.min(arr[i][j],arr[i][k]+arr[k][j]);
                }
            }
        }
        for(int i=0;i<n;i++){
            answer = Math.min(answer, arr[s-1][i]+arr[i][a-1]+arr[i][b-1]);
        }
        return answer;
    }
}