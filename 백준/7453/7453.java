import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class BOJ7453{
    public static long solution(int T, int [][] arr) {
        long answer = 0;
        int [] CD = new int[T*T];
        int [] AB = new int[T*T];
        int idx = 0;
        for(int i=0;i<T;i++){
            for(int j=0;j<T;j++){
                CD[idx] = arr[i][2]+arr[j][3];
                AB[idx] = arr[i][0] +arr[j][1];
                idx++;
            }
        }
        Arrays.sort(CD);
        Arrays.sort(AB);
        /*
        for(int i=0;i<T;i++){
            for(int j=0; j<T;j++){
                int l_index = lower_bound(-key,CD);
                int r_index = upper_bound(-key,CD);
                answer += r_index - l_index;
            }
        }
         */
        for(int i : AB){
            int l_index = lower_bound(-i,CD);
            int r_index = upper_bound(-i,CD);
            answer += r_index - l_index;
        }
        return answer;

    }
    public static int upper_bound(int key, int [] arr){
        int left = 0;
        int right = arr.length;

        while(left<right){
            int mid = (left+right)/2;
            if(arr[mid]<=key)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
    public static int lower_bound(int key, int [] arr){
        int left = 0;
        int right = arr.length;
        while(left<right){
            int mid = (left+right)/2;
            if(arr[mid]<key)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
}
public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int [][] arr = new int[T][];
        for(int i=0; i<T;i++){
            arr[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(k->Integer.parseInt(k)).toArray();
        }
        long answer = BOJ7453.solution(T,arr);
        System.out.println(answer);
    }
}