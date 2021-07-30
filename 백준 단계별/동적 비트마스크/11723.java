import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String args[]) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(bf.readLine());
        StringBuffer sb = new StringBuffer();
        int bitmask = 0;
        for(int i=0;i<M;i++){
            String [] arr  = bf.readLine().split(" ");
            int num =0;
            if(!arr[0].equals("all") && !arr[0].equals("empty"))
                num = Integer.parseInt(arr[1]);
            switch (arr[0]){
                case "add":
                    bitmask = bitmask | 1<<(num-1);
                    break;
                case "check":
                    if((bitmask & 1<<(num-1)) != 0)
                        sb.append("1\n");
                    else
                        sb.append("0\n");
                    break;
                case "remove":
                    bitmask = bitmask & ~(1<<(num-1));
                    break;
                case "toggle":
                    bitmask = bitmask ^ (1<<(num-1));
                    break;
                case "all":
                    bitmask = (1<<20)-1;
                    break;
                case "empty":
                    bitmask = 0;
                    break;
            }
        }
        System.out.println(sb.toString());
    }
}