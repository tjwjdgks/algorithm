import java.util.*;




public class Main{
    public static long [][] origianl = {{1,1},{1,0}};
    public static long Mod = 1000000007;
    public static long[][] getAnswer(long n){
        if(n == 1 || n == 0){
            return origianl;
        }
        long[][] temp = getAnswer(n/2);
        temp = multiplyM(temp,temp);
        if(n%2 == 1)
            temp = multiplyM(temp,origianl);
        return temp;
    }
    public static long [][] multiplyM(long [][] a, long[][] b){
        long[][] returnarr = new long[2][2];
        returnarr[0][0] = (a[0][0]*b[0][0]+a[0][1]*b[1][0])%Mod;
        returnarr[0][1] = (a[0][0]*b[0][1]+a[0][1]*b[1][1])%Mod;
        returnarr[1][0] = (a[1][0]*b[0][0]+a[1][1]*b[1][0])%Mod;
        returnarr[1][1] = (a[1][0]*b[0][1]+a[1][1]*b[1][1])%Mod;
        return returnarr;
    }
    public static void main(String args[])  {
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        if(n == 0 || n == 1)
            System.out.println(n);
        else{
            long [][]answerarr =getAnswer(n-1);
            System.out.println(answerarr[0][0]);
        }
    }
}