import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.*;

public class Main {
    public static ArrayList<ArrayList<int[]>> arr;
    public static int maxnum;
    public static int maxtotal;
    public static boolean [] check;
    public static void dfs(int start, int num){
        if(num> maxtotal){
            maxtotal = num;
            maxnum = start;
        }
        ArrayList<int[]> curarr = arr.get(start);
        for(int [] i : curarr){
            if(check[i[0]] == false){
                check[i[0]] = true;
                dfs(i[0],num+i[1]);
            }
        }
    }
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        arr = new ArrayList<>(N+1);
        check = new boolean[N+1];
        for(int i=0;i<=N;i++)
            arr.add(new ArrayList<>());
        StringTokenizer st;
        for(int i=0; i<N;i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = -1;
            while((to = Integer.parseInt(st.nextToken()))!=-1){
                int val = Integer.parseInt(st.nextToken());
                arr.get(from).add(new int[]{to,val});
            }
        }
        check[1] = true;
        maxtotal =0;
        maxnum = 0;
        dfs(1,0);
        maxtotal = 0;
        Arrays.fill(check,false);
        check[maxnum] = true;
        dfs(maxnum,0);
        System.out.println(maxtotal);
    }
}