import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//벨만 포드
//출력초과 조심
public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        ArrayList<ArrayList<int[]>> arr =new ArrayList<>(N);
        for(int i=0; i<N;i++)
            arr.add(new ArrayList<>());
        for(int i=0;i<M;i++){
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken())-1;
            int to = Integer.parseInt(st.nextToken())-1;
            int val = Integer.parseInt(st.nextToken());
            arr.get(from).add(new int[]{to,val});
        }
        long []minarr = new long[N];
        Arrays.fill(minarr,Integer.MAX_VALUE);
        minarr[0] = 0;
        // vertex-1 번 반복
        boolean cycle = false;
        for(int i=1;i<=N;i++){
            for(int j=0;j<N;j++){
                ArrayList<int[]> curarr = arr.get(j);
                for(int[] k : curarr){
                    if(minarr[j] != Integer.MAX_VALUE && minarr[k[0]]> minarr[j]+k[1]){
                        minarr[k[0]] = minarr[j]+k[1];
                        if(i==N)
                            cycle = true;
                    }
                }
            }
        }
        if(cycle)
            System.out.println(-1);
        else{
            StringBuffer sb = new StringBuffer();
            for(int i =1; i<N;i++){
                if(minarr[i] == Integer.MAX_VALUE)
                    sb.append("-1\n");
                else
                    sb.append(minarr[i]).append("\n");
            }
            System.out.println(sb.toString());
        }

    }
}