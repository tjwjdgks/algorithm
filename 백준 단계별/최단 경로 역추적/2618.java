import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.*;

public class Main {
    public static int [][] dp;
    public static int [][] arr;
    public static int N,M;
    public static StringBuffer sb = new StringBuffer();
    public static int dfs(int left, int right){
        if(left == M || right == M) return 0;
        if(dp[left][right] != -1 ) return dp[left][right];
        dp[left][right] = 987654321;
        int tempstage = Math.max(left,right)+1;
        int distleft = getDistance(tempstage,left,true);
        int distright = getDistance(tempstage,right, false);

        int curleft = dfs(tempstage, right) + distleft;
        int curright = dfs(left, tempstage) + distright;
        return dp[left][right] = Math.min(curleft,curright);
    }
    // true left false right
    public static int getDistance(int nextstage, int curstage,boolean check){
        int answer =0;
        if(check){
            answer  = (curstage ==0) ? Math.abs(arr[nextstage][0]- 1) + Math.abs(arr[nextstage][1]-1) :
                    Math.abs(arr[nextstage][0]-arr[curstage][0]) + Math.abs(arr[nextstage][1]-arr[curstage][1]);
        }
        else{
            answer  = (curstage ==0) ? Math.abs(arr[nextstage][0]- N) + Math.abs(arr[nextstage][1]-N) :
                    Math.abs(arr[nextstage][0]-arr[curstage][0]) + Math.abs(arr[nextstage][1]-arr[curstage][1]);
        }
        return answer;
    }
    public static void traceRoute(int left, int right){
        if(left == M || right == M) return;
        int tempstage = Math.max(left,right)+1;
        int leftdist = getDistance(tempstage,left,true);
        int rightdist = getDistance(tempstage,right,false);
        if(dp[tempstage][right]+leftdist>dp[left][tempstage]+rightdist){
            sb.append(2).append("\n");
            traceRoute(left,tempstage);
        }
        else{
            sb.append(1).append("\n");
            traceRoute(tempstage,right);
        }
    }
    public static void main(String args[]) throws IOException{
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bufferedReader.readLine());
        M = Integer.parseInt(bufferedReader.readLine());
        dp = new int[M+1][M+1];
        arr = new int[M+1][2];
        for(int [] i : dp)
            Arrays.fill(i,-1);
        StringTokenizer st;
        for(int i=1; i<=M;i++){
            st = new StringTokenizer(bufferedReader.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }
        System.out.println(dfs(0,0));
        traceRoute(0,0);
        System.out.println(sb.toString());
    }
}