import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{1,0,0});
        boolean check[][] = new boolean[2001][2001];
        while(!queue.isEmpty()){
            int [] curarr = queue.poll();
            if(curarr[0] == N){
                System.out.println(curarr[2]);
                break;
            }
            int step1clip = curarr[0];
            int step2image = curarr[1] + curarr[0];
            int step3imageremove = curarr[0]-1;

            if(step1clip<2001 && check[curarr[0]][step1clip] == false){
                check[curarr[0]][step1clip] = true;
                queue.add(new int[]{curarr[0],step1clip,curarr[2]+1});
            }
            if(step2image<2001 && curarr[1] != 0 && check[step2image][curarr[1]] == false){
                check[step2image][curarr[1]] = true;
                queue.add(new int[]{step2image,curarr[1],curarr[2]+1});
            }
            if(step3imageremove>0 && check[step3imageremove][curarr[1]] == false){
                check[step3imageremove][curarr[1]] = true;
                queue.add(new int[]{step3imageremove,curarr[1],curarr[2]+1});
            }
        }
    }
}