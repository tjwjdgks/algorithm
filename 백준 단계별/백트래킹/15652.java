import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.joining;



public class Main {
    public static StringBuilder sb= new StringBuilder();
    public static int N;
    public static int M;
    public static void getAnswer(int firstidx, int count, String a){
        if(count == M){
            sb.append(a+"\n");
            return;
        }
        for(int i=firstidx;i<=N;i++){
            getAnswer(i,count+1,(count == 0)?a+(i):a+" "+(i));
        }
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        getAnswer(1,0,"");
        System.out.println(sb.toString());
    }
}
