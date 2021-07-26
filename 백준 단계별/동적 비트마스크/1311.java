import java.awt.desktop.SystemSleepEvent;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static int [][] dp;
    public static int N;
    public static int [][] arr;
    public static final int INF = 987654321;
    public static int dfs(int step, int flag){
        if(step>=N)
            return flag == (1<<N)-1 ? 0 : INF;
        if(dp[step][flag] != -1)
            return dp[step][flag];
        dp[step][flag] = INF;
        for(int i=0;i<N;i++){
            if((flag &(1<<i))> 0) continue;
            dp[step][flag] = Math.min(dfs(step+1,flag | (1<<i))+arr[step][i],dp[step][flag]);
        }
        return dp[step][flag];
    }
    public static void main(String args[]) throws IOException{
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bufferedReader.readLine());
        dp = new int[20][1<<21];
        arr = new int[N][N];
        for(int i=0;i<N;i++){
            arr[i] = Arrays.stream(bufferedReader.readLine().split(" ")).mapToInt(k->Integer.parseInt(k)).toArray();
        }
        for(int i=0;i<N;i++)
            Arrays.fill(dp[i],-1);
        int answer = dfs(0,0);
        System.out.println(answer);
    }
}