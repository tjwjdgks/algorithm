import java.awt.desktop.SystemSleepEvent;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.joining;



public class Main {
    public static int dp[][];
    public static int getAnswer(int a, int b){
        if(b<0) return 0;
        if(a == b || b == 0) return dp[a][b] = 1;
        if(dp[a][b]!= 0 )return dp[a][b];
        return dp[a][b] = getAnswer(a-1,b-1)%10007 + getAnswer(a-1,b)%10007;
    }
    public static void main(String args[]) throws IOException{
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b= scanner.nextInt();
        dp = new int[a+1][a+1];
        System.out.println(getAnswer(a,b)%10007);
    }
}
