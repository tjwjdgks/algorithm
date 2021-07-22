import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static ArrayList<ArrayList<Integer>> nodearr;
    public static int[] node;
    public static int[][] dp;
    public static int dfs(int start,int pre, int flag){
        if(dp[flag][start] != -1) return dp[flag][start];
        int answer =0;
        if(flag == 1)
            answer = node[start];
        ArrayList<Integer> arr = nodearr.get(start);
        for(int i : arr){
            if(pre == i) continue;
            if(flag == 1){
                answer += dfs(i,start,0);
            }
            else{
                answer += Math.max(dfs(i,start,0),dfs(i,start,1));
            }
        }
        return dp[flag][start] = answer;
    }
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        node = Arrays.stream(br.readLine().split(" ")).mapToInt(i->Integer.parseInt(i)).toArray();
        nodearr = new ArrayList<>(N);
        dp = new int[2][N];
        for(int i=0;i<2;i++)
            Arrays.fill(dp[i],-1);
        for(int i=0;i<N;i++)
            nodearr.add(new ArrayList<>());
        StringTokenizer st;
        for(int i=0;i<N-1;i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken())-1;
            int to = Integer.parseInt(st.nextToken())-1;
            nodearr.get(from).add(to);
            nodearr.get(to).add(from);
        }
        int temp1 = dfs(0,-1,0);
        int temp2 = dfs(0,-1,1);
        System.out.println(Math.max(temp1,temp2));
    }
}