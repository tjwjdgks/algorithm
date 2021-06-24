import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;


public class Main {

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int num = 665;
        int count = 0;
        while(true){
            if(String.valueOf(num).contains("666")){
                count++;
            }
            if(count == N){
                System.out.println(num);
                break;
            }
            num++;
        }
    }
}
