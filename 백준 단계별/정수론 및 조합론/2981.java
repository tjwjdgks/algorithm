import java.awt.desktop.SystemSleepEvent;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.joining;



public class Main {
    public static int getGCD(int first, int second){
        if(second ==0)
            return first;
        return getGCD(second, first%second);
    }
    public static void main(String args[]) throws IOException{
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bufferedReader.readLine());
        int [] arr = new int[N];
        for(int i=0; i<N;i++){
            arr[i] = Integer.parseInt(bufferedReader.readLine());
        }
        Arrays.sort(arr);
        int gcdn = arr[1] -arr[0];
        for(int i=2; i<N;i++){
            if(arr[i]-arr[i-1]<gcdn){
                gcdn = getGCD(gcdn,arr[i]-arr[i-1]);
            }
            else
                gcdn = getGCD(arr[i]-arr[i-1],gcdn);
        }
        StringBuffer sb = new StringBuffer();
        for(int i=2; i<=gcdn;i++){
            if(gcdn%i==0)
                sb.append(i+" ");
        }
        System.out.println(sb.toString());
    }
}