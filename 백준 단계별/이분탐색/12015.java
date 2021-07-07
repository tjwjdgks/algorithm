import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main{
   public static void main(String args[]) throws IOException{
     BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
     int N = Integer.parseInt(br.readLine());
     int [] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(i->Integer.parseInt(i)).toArray();
     ArrayList<Integer> arrayList = new ArrayList<>();
     arrayList.add(-9999);
     for(int i =0; i<N;i++){
         int val = arr[i];
         if(arrayList.get(arrayList.size()-1)<val)
             arrayList.add(val);
         else{
             int low = 0;
             int high = arrayList.size()-1;
             while(low <high){
                 int mid = (low+high)/2;
                 if(arrayList.get(mid)<val)
                     low = mid+1;
                 else
                     high = mid;
             }
             arrayList.set(low,val);
         }
     }
     System.out.println(arrayList.size()-1);
   }
}
