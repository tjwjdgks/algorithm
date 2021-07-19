import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.*;

public class Main {
    public static int[] idx;
    public static int[] pre;
    public static int[] in;
    public static int[] post;
    public static int count = 0;
    public static void getpre(int instart,int inend, int poststart, int postend){
        if(instart > inend || poststart>postend) return;
        int root = post[postend];
        pre[count++] = root;
        getpre(instart,idx[root]-1,poststart,poststart+(idx[root]-instart)-1);
        getpre(idx[root]+1,inend,poststart+(idx[root]-instart),postend-1);
    }
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        pre = new int[N];
        in = Arrays.stream(br.readLine().split(" ")).mapToInt(i->Integer.parseInt(i)).toArray();
        post = Arrays.stream(br.readLine().split(" ")).mapToInt(i->Integer.parseInt(i)).toArray();
        idx = new int[N+1];
        for(int i=0;i<N;i++){
            idx[in[i]]= i;
        }
        getpre(0,N-1,0,N-1);
        StringBuffer sb = new StringBuffer();
        for(int i=0;i<N;i++){
            sb.append(pre[i]).append(" ");
        }
        
        System.out.println(sb.toString());
    }
}