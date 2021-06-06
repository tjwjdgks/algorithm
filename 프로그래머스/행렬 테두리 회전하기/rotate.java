class Solution {
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        int[][] arr= new int[rows][columns];
        int count =1;
        for(int i=0; i<rows;i++){
            for(int j=0; j<columns;j++){
                arr[i][j] = count;
                count++;
            }
        }
        for(int i=0; i<queries.length;i++){
            int y1 = queries[i][0]-1;
            int x1 = queries[i][1]-1;
            int y2 = queries[i][2]-1;
            int x2 = queries[i][3]-1;
            int tempnum = arr[y1][x1];
            int minnum = arr[y1][x1];
            for(int j=y1;j<y2;j++){
                arr[j][x1] = arr[j+1][x1];
                minnum =Math.min(minnum,arr[j][x1]);
            }
            for(int j=x1;j<x2;j++){
                arr[y2][j] = arr[y2][j+1];
                minnum =Math.min(minnum,arr[y2][j]);
            }
            for(int j=y2;j>y1;j--){
                arr[j][x2] = arr[j-1][x2];
                minnum =Math.min(minnum,arr[j][x2]);
            }
            for(int j=x2;j>x1;j--){
                arr[y1][j] = arr[y1][j-1];
                minnum = Math.min(minnum, arr[y1][j]);
            }
            arr[y1][x1+1] = tempnum; 
            answer[i] = minnum;
        }
        return answer;
    }
}