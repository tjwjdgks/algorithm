import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;
import java.util.stream.Collectors;


public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testcase = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<testcase;i++){
            String[] temparr = br.readLine().split(" ");
            int first = Integer.parseInt(temparr[0]);
            int second = Integer.parseInt(temparr[1]);
            int gap  = second-first;
            if(gap <= 3)
                sb.append(gap).append("\n");
            else{
                int tempnum = (int)Math.sqrt(gap);
                int answer = 2*tempnum-1;
                if(tempnum*tempnum == gap)
                    sb.append(answer).append("\n");
                else{
                    answer++;
                    if(tempnum*tempnum+tempnum<gap)
                        answer++;
                    sb.append(answer).append("\n");
                }

            }

        }
        System.out.println(sb.toString());
    }
}