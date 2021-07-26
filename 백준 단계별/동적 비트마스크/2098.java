import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static int N;
    public static int [][] dp;
    public static int [][] arr;
    public static final int INF = 987654321;
    public static int dfs(int cur,int flag){
        if(flag == (1<<N)-1){
            if(arr[cur][0] == 0) return INF;
            else return arr[cur][0];
        }
        if(dp[cur][flag] != -1)
            return dp[cur][flag];
        dp[cur][flag] = INF;
        for(int i=1;i<N;i++){
            if((flag & (1<<i)) == 0 && arr[cur][i] !=0 )
                dp[cur][flag] = Math.min(dp[cur][flag], dfs(i,flag | (1<<i))+arr[cur][i]);
        }
        return dp[cur][flag];
    }
    public static void main(String args[]) throws IOException{
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bufferedReader.readLine());
        arr= new int[N][];
        dp = new int[N][1<<N+1];
        for(int i=0;i<N;i++){
            arr[i] = Arrays.stream(bufferedReader.readLine().split(" ")).mapToInt(k->Integer.parseInt(k)).toArray();
        }
        for(int i=0;i<N;i++)
            Arrays.fill(dp[i],-1);

        int answer = dfs(0,1);
        System.out.println(answer);
    }
}