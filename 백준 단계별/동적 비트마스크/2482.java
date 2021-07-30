import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.CookieHandler;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int K = Integer.parseInt(br.readLine());
        int [][] dp = new int[N+1][N+1];
        for(int i=0; i<=N;i++){
            dp[i][0] = 1;
            dp[i][1] = i;
        }
        final int Mod = 1_000_000_003;
        for(int i=2;i<=N;i++){
            for(int j=2;j*2<=i+1;j++){
                dp[i][j] = (dp[i-1][j] + dp[i-2][j-1])%Mod;
            }
        }
        int answer = (dp[N-3][K-1] + dp[N-1][K])%Mod;
        System.out.println(answer);

    }
}