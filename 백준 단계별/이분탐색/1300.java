import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main{
   public static void main(String args[]) throws IOException{
      Scanner scanner = new Scanner(System.in);
      int N = scanner.nextInt();
      int k = scanner.nextInt();
      int low = 1;
      int high = k;
      int answer = -1;
      while(low<=high){
          int count =0;
          int mid = (low+high)/2;
          for(int i=1;i<=N;i++){
              count += Math.min(mid/i,N);
          }
          if(count<k){
              low = mid+1;
          }
          else{
              answer = mid;
              high = mid-1;
          }
      }
      System.out.println(answer);
   }
}

