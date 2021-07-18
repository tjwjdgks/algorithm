import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        ArrayList<ArrayList<int[]>> arr = new ArrayList<>(n+1);
        for(int i =0 ;i<=n;i++)
            arr.add(new ArrayList<>());
        StringTokenizer st;
        for(int i=0;i<m;i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int val = Integer.parseInt(st.nextToken());
            boolean check = true;
            arr.get(from).add(new int[]{to,val});
        }
        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());

        int [] dp = new int [n+1];
        Arrays.fill(dp,Integer.MAX_VALUE/2);
        int [] prev = new int[n+1];
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> {
            if(o1[1]== o2[1])
                return o1[0] - o2[0];
            return o1[1] - o2[1];
        });
        pq.add(new int[]{start,0});
        dp[start] = 0;
        while(!pq.isEmpty()){
            int [] cur = pq.poll();
            if(cur[0] == end ) break;
            ArrayList<int[]> curarr = arr.get(cur[0]);
            if(dp[cur[0]]>cur[1]) continue;
            for(int [] i : curarr){
                if(dp[i[0]]>i[1]+cur[1]){
                    dp[i[0]]  = i[1]+cur[1];
                    prev[i[0]] = cur[0];
                    pq.add(new int[]{i[0],i[1]+cur[1]});
                }
            }
        }
        System.out.println(dp[end]);
        Stack<Integer> s = new Stack<>();
        s.push(end);
        int idx = end;
        while(idx != start){
            s.push(prev[idx]);
            idx = prev[idx];
        }
        System.out.println(s.size());
        StringBuffer sb = new StringBuffer();
        while(!s.isEmpty()){
            sb.append(s.pop()).append(" ");
        }
        System.out.println(sb.toString());
    }
}