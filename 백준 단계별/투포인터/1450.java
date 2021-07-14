import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

//Meet In the middle 문제
public class Main {
    public static int N;
    public static int C;
    public static int [] arr;
    public static void dfs(int start,int end,int sum,ArrayList<Integer> curarr){
        if(sum>C) return;
        if(start == end){

            curarr.add(sum);
            return;
        }
        // 포함
        dfs(start+1,end,sum+arr[start],curarr);
        // 미포함
        dfs(start+1,end,sum,curarr);

    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        arr = Arrays.stream(br.readLine().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        dfs(0,N/2,0,left);
        dfs(N/2,N,0,right);
        Collections.sort(left);
        Collections.sort(right);
        int answer = 0;
        for(int i=0,j=right.size()-1;i<left.size() && j>=0;i++){
            while(left.get(i)+right.get(j)>C) j--;
            answer += j+1;
        }
        System.out.println(answer);
    }
}