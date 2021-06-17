import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        int year  = 0;
        if(num%4 == 0 && (num%400 == 0 || num%100!=0 ))
            year = 1;
        System.out.println(year);
    }
}
