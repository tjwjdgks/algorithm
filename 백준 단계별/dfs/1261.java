import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException{
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       StringTokenizer st = new StringTokenizer(br.readLine());
       int w = Integer.parseInt(st.nextToken());
       int h = Integer.parseInt(st.nextToken());

       int [][] arr = new int[h][];

       for(int i=0;i<h;i++){
           arr[i] = Arrays.stream(br.readLine().split("")).mapToInt(k->Integer.parseInt(k)).toArray();
       }

       boolean [][] check = new boolean[h][w];
       // h w bricknum
       Queue<int[]>  pq = new PriorityQueue<>((o1, o2) -> {
          return o1[2] - o2[2];
       });
       int [] dy = {0,0,-1,1};
       int [] dx = {1,-1,0,0};
       pq.add(new int[]{0,0,0});
       while(!pq.isEmpty()){
           int [] curarr = pq.poll();
           if(curarr[0] == h-1 && curarr[1] == w-1){
               System.out.println(curarr[2]);
               break;
           }
           for(int i=0;i<4; i++){
               int tempy  = curarr[0] + dy[i];
               int tempx = curarr[1] + dx[i];
               if(tempy>=0 && tempy<h && tempx>=0 && tempx<w && check[tempy][tempx] == false){
                   check[tempy][tempx] = true;
                   if(arr[tempy][tempx] == 1)
                       pq.add(new int[]{tempy,tempx,curarr[2]+1});
                   else
                       pq.add(new int[]{tempy,tempx,curarr[2]});
               }
           }
       }
    }
}