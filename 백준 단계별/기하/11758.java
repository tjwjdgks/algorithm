import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

// 외적 문제
// 0 A , 1 B , 2 C
public class Main {
    // ccw
    public static int getCCW(int [][] threePointarr){
        int answer = -1;
        int AbyBx = threePointarr[1][0] - threePointarr[0][0]; // A.x -> B.x
        int AbyBy = threePointarr[1][1] - threePointarr[0][1]; // A.y -> B.y

        int BbyCx = threePointarr[2][0] - threePointarr[1][0]; // B.x -> C.x
        int BbyCy = threePointarr[2][1] - threePointarr[1][1]; // B.y -> C.y

        // A->B X  B->C 외적
        answer = AbyBx*BbyCy - AbyBy*BbyCx;
        if(answer >0 )
            return 1;
        if(answer<0)
            return -1;
        else
            return 0;
    }
 
    public static void main(String args[]) throws IOException{
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        int [][] pointarr = new int[3][2];
        StringTokenizer st;
        for(int i=0;i<3; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            pointarr[i][0] = x;
            pointarr[i][1] = y;
        }
        System.out.println(getCCW(pointarr));
    }
}