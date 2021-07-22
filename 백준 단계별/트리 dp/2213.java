import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static int [][] dp;
    public static int [] node;
    public static ArrayList<ArrayList<Integer>> nodearr;
    // flag 소비 0 소비x 1 소비o
    public static int dfs(int start, int pre, int flag){
        int answer = dp[flag][start];
        if(answer != -1)
            return dp[flag][start];
        if(flag == 0){
            answer =0;
        }
        else{
            answer = node[start];
        }
        ArrayList<Integer> curarr = nodearr.get(start);
        for(int i: curarr){
            if(i == pre) continue;
            if(flag == 1){
                answer += dfs(i,start,0);
            }
            else{
                answer += Math.max(dfs(i,start,0),dfs(i,start,1));
            }
        }
        return dp[flag][start] = answer;
    }
    // 소비 0 x 소비 1 o
    public static ArrayList<Integer>  arr = new ArrayList<>();
    public static void tracking(int start, int pre, int flag){
        if(flag == 1)
            arr.add(start);
        ArrayList<Integer> curarr = nodearr.get(start);
        for(int i : curarr){
            if(i == pre) continue;
            if(flag == 1)
                tracking(i,start,0);
            else{
                if(dp[0][i]>=dp[1][i])
                    tracking(i,start,0);
                else
                    tracking(i,start,1);
            }
        }
    }
    public static void main(String args[]) throws IOException{
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        node = new int[N+1];
        dp = new int[2][N+1];
        for(int i=0;i<2;i++)
            Arrays.fill(dp[i],-1);
        String [] snode = br.readLine().split(" ");
        for(int i=1;i<=N; i++){
            node[i] = Integer.parseInt(snode[i-1]);
        }
        nodearr = new ArrayList<>(N+1);
        for(int i=0;i<=N;i++)
            nodearr.add(new ArrayList<>());
        for(int i=0;i<N-1; i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            nodearr.get(from).add(to);
            nodearr.get(to).add(from);
        }
        int temp1 = dfs(1,-1,0);
        int temp2 = dfs(1,-1,1);
        if(temp1>temp2){
            tracking(1,-1,0);
        }
        else{
            tracking(1,-1,1);
        }
        System.out.println(Math.max(temp1,temp2));
        System.out.println(arr.stream().sorted().map(i->i.toString()).collect(Collectors.joining(" ")));
    }
}