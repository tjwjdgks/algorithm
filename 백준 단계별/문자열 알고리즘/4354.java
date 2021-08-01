import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static int faliureFunction(String s){
        int [] arr = new int [s.length()];
        int start = 0;
        for(int i=1;i<s.length();i++){
            while(start > 0 && s.charAt(i) != s.charAt(start)){
                start  = arr[start-1];
            }
            if(s.charAt(start) == s.charAt(i))
                arr[i] = ++start;
        }
        int answer =-1;
        if(s.length()%(s.length()- arr[s.length()-1])!=0)
            answer =1;
        else answer = s.length() / (s.length() - arr[s.length()-1]);
        return answer;
    }
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        while(true){
            String  s  = br.readLine();
            if(s.equals("."))
                break;
            int curanswer = faliureFunction(s);
            sb.append(curanswer).append("\n");
        }
        System.out.println(sb.toString());
    }
}