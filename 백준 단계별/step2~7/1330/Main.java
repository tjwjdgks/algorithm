import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

class b1330 {
    public String getAnswer(int a,int b){
        String answer = "";
        if(a> b) answer = ">";
        else if (a<b) answer = "<";
        else answer = "==";
        return answer;
    }
}
public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String input = bufferedReader.readLine();
        int [] arr = Arrays.stream(input.split(" ")).mapToInt(i->Integer.parseInt(i)).toArray();
        b1330 b = new b1330();
        String answer = b.getAnswer(arr[0],arr[1]);
        System.out.println(answer);
    }
}
