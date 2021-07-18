import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.*;

public class Main {
    public static void getTrace(int [][] route, int start, int end, LinkedList<Integer> arr){
        if(route[start][end] == 0){
            arr.add(start);
            arr.add(end);
            return;
        }
        getTrace(route,start,route[start][end],arr);
        arr.removeLast();
        getTrace(route,route[start][end],end,arr);
    }
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        int [][] dp = new int[n+1][n+1];
        int [][] route = new int[n+1][n+1];
        for(int i=0;i<dp.length;i++)
            Arrays.fill(dp[i],Integer.MAX_VALUE/2);
        StringTokenizer st;
        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int val = Integer.parseInt(st.nextToken());
            dp[from][to] = Math.min(dp[from][to],val);
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i==j) continue;
                    if(dp[i][j]>dp[i][k]+dp[k][j]){
                        dp[i][j] = dp[i][k]+dp[k][j];
                        route[i][j] =k;
                    }
                }
            }
        }
        StringBuffer sb = new StringBuffer();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j] == Integer.MAX_VALUE/2) sb.append(0).append(" ");
                else sb.append(dp[i][j]).append(" ");
            }
            sb.append("\n");
        }
        LinkedList<Integer> arr = new LinkedList<>();
        for(int i=1;i<=n;i++){
            for(int j=1; j<=n;j++){
                arr.clear();
                if(dp[i][j] == Integer.MAX_VALUE/2){
                    sb.append("0\n");
                    continue;
                }
                getTrace(route,i,j,arr);
                sb.append(arr.size()).append(" ");
                for(int k : arr)
                    sb.append(k).append(" ");
                sb.append("\n");
            }
        }
        System.out.println(sb.toString());
    }
}