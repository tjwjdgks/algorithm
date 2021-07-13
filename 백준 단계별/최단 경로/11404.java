import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int edge = Integer.parseInt(br.readLine());
        StringTokenizer st;
        int [][] arr =new int[n][n];
        final int INF = 100000*100;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j) arr[i][j] = 0;
                else arr[i][j] = INF;
            }
        }
        for(int i=0;i<edge;i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken())-1;
            int to = Integer.parseInt(st.nextToken())-1;
            int val = Integer.parseInt(st.nextToken());
            arr[from][to] = Math.min(arr[from][to],val);
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    arr[i][j] = Math.min(arr[i][j],arr[i][k]+arr[k][j]);
                }
            }
        }
        StringBuffer sb = new StringBuffer();
        for(int i=0;i<n;i++){
            for(int j=0; j<n;j++){
                if(arr[i][j] == INF)
                    sb.append(0).append(" ");
                else
                    sb.append(arr[i][j]).append(" ");
            }
            sb.append("\n");
        }
        System.out.println(sb.toString());
    }
}