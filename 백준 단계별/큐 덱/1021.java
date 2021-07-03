import java.io.*;
import java.lang.reflect.Array;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;


public class Main {
    public static void main(String args[]) throws IOException{
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        ArrayDeque<Integer> deque = new ArrayDeque<>();
        StringTokenizer st = new StringTokenizer(bufferedReader.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int arr[] = Arrays.stream(bufferedReader.readLine().split(" ")).mapToInt(i->Integer.parseInt(i)).toArray();
        for(int i=1; i<=N;i++){
            deque.add(i);
        }
        int totalcount = 0;
        for(int i=0;i<M;i++){
            int count = 0;
            for(int n : deque){
                if(arr[i] == n) break;
                count++;
            }
            if(count<deque.size()-count){
                for(int j=0; j<count;j++){
                    deque.addLast(deque.removeFirst());
                    totalcount++;
                }
            }
            else{
                for(int j = 0; j<deque.size()-count;j++){
                    deque.addFirst(deque.removeLast());
                    totalcount++;
                }
            }
            deque.removeFirst();
        }
        System.out.println(totalcount);
    }
}
