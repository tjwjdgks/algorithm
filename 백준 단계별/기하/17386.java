import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

// 외적 문제
public class Main {
    public static int getCCW(long [] F, long [] M, long [] L){
        long FMX = M[0] - F[0];
        long FMY = M[1]-F[1];
        long MLX = L[0] - M[0];
        long MLY = L[1] - M[1];

        // external product
        long ep  = FMX*MLY - FMY*MLX;
        if(ep>0) return 1;
        else if(ep<0) return -1;
        else return 0;
    }
    // ABCD
    public static int getCross(long [][] arr){
        int ABC = getCCW(arr[0],arr[1],arr[2]);
        int ABD = getCCW(arr[0],arr[1],arr[3]);

        int CDA = getCCW(arr[2],arr[3],arr[0]);
        int CDB = getCCW(arr[2],arr[3],arr[1]);

        if((ABC*ABD < 0) && (CDA *CDB <0))
            return 1;
        else
            return 0;
    }
    public static void main(String args[]) throws IOException{
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        long [][] arr = new long[4][2];
        for(int i=0;i<2;i++){
            String[] s = br.readLine().split(" ");
            for(int j=0;j<s.length;j++){
                arr[i*2+j/2][j%2] = Integer.parseInt(s[j]);
            }
        }
        int answer = getCross(arr);
        System.out.println(answer);
    }
}