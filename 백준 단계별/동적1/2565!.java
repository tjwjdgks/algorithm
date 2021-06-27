import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.joining;



public class Main {

    public static void main(String args[]) throws IOException {
        Scanner in = new Scanner(System.in);
        int N  = in.nextInt();
        int [] dp = new int[N];
        int [][] arr = new int[N][2];
        for(int i=0; i<N;i++){
            arr[i][0] = in.nextInt();
            arr[i][1] = in.nextInt();
        }
        Arrays.sort(arr,(o1, o2) -> {
            return o1[0]-o2[0];
        });
        for(int i=0;i<dp.length;i++){
            dp[i] = 1;
            for(int j=0;j<i;j++){
                if(arr[i][1]>arr[j][1])
                    dp[i] = Math.max(dp[i],dp[j]+1);
            }
        }
        int total =0;
        for(int i=0;i<dp.length;i++){
            total = Math.max(total,dp[i]);
        }
        System.out.println(N-total);
    }
}