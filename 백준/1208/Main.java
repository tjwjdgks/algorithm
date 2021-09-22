import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;


// meet In the middle
public class Main {
    public static int []arr;
    public static long answer=0;
    public static int S=0;
    public static Map<Integer,Integer> map = new HashMap<>();
    public static void leftDfs(int start, int end,int sum){
        if(start == end){
            map.put(sum,map.getOrDefault(sum,0)+1);
            return;
        }
        leftDfs(start+1,end,sum+arr[start]);
        leftDfs(start+1,end,sum);
    }
    public static void rightDfs(int start, int end, int sum){
        if(start == end){
            if(map.containsKey(S-sum))
                answer += map.get(S-sum);
            return;
        }
        rightDfs(start+1,end,sum+arr[start]);
        rightDfs(start+1,end,sum);
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        arr = Arrays.stream(br.readLine().split(" ")).mapToInt(k->Integer.parseInt(k)).toArray();
        leftDfs(0,N/2,0);
        rightDfs(N/2,N,0);
        if(S == 0)
            answer--;
        System.out.println(answer);
    }
}
