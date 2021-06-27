import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.joining;



public class Main {

    public static void main(String args[]) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      char[] f = br.readLine().toCharArray();
      char[] s = br.readLine().toCharArray();
      int [][] dp = new int[f.length+1][s.length+1];
      for(int i=1; i<=f.length;i++){
          for(int j=1; j<=s.length;j++){
              if(f[i-1] == s[j-1]){
                  dp[i][j] = Math.max(dp[i][j],dp[i-1][j-1]+1);
              }
              else
                  dp[i][j] = Math.max(dp[i-1][j],dp[i][j-1]);
          }
      }
      System.out.println(dp[f.length][s.length]);
    }
}