import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;


public class Main {
    public static void main(String args[]) throws IOException{
        int []arr = new int[8001];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int idxzero = 4000;
        for(int i=0; i<N;i++){
           int tempNUM = Integer.parseInt(br.readLine());
           arr[idxzero+tempNUM]++;
        }
        double total = 0;
        int middlenum=0;
        int tempcount =0;
        int minnum = 4002;
        int maxnum = -5000;
        int frenum = 0;
        boolean check = false;
        int freidxnum = 0;
        boolean idxcheck = true;
        for(int i=0; i<arr.length;i++){
            if(arr[i] !=0){
                if(tempcount+arr[i]>=N/2+1 && idxcheck){
                    middlenum = i-idxzero;
                    idxcheck= false;
                }
                tempcount += arr[i];
                minnum = Math.min(minnum,i-idxzero);
                maxnum = Math.max(maxnum,i-idxzero);
                total += (i-idxzero)*arr[i];
                if(freidxnum<arr[i]){
                    frenum = i-idxzero;
                    freidxnum = arr[i];
                    check = false;
                }
                else if(freidxnum==arr[i] && check == false){
                    frenum = i-idxzero;
                    check= true;
                }
            }
        }
        long totalround = Math.round(Math.abs(total)/N);
        if(total<0)
            totalround *= -1;
        System.out.println(totalround);
        System.out.println(middlenum);
        System.out.println(frenum);
        System.out.println(maxnum-minnum);
    }
}