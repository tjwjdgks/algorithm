import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int a = Character.getNumericValue(br.read());
        for(int i=1; i<=9; i++){
            System.out.println(a +" * " + i+ " = " + (a*i));
        }
    }
}
