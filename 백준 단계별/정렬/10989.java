import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;


public class Main {
    public static void main(String args[]) throws IOException{
        int []arr = new int[10001];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(br.readLine());
        for(int i =0; i<cases;i++){
            int curnum = Integer.parseInt(br.readLine());
            arr[curnum]++;
        }
        StringBuilder sb = new StringBuilder();
        for(int i=1; i<arr.length;i++){
            for(int j=1;j<=arr[i];j++){
                sb.append(i+"\n");
            }
        }
        System.out.println(sb.toString());
    }
}