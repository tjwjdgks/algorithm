import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static int [] arr;
    public static void Pi(String P){
        int start = 0;
        for(int i=1;i<P.length();i++){
            while(start > 0 && P.charAt(i) != P.charAt(start))
                start = arr[start-1];
            if(P.charAt(start) == P.charAt(i))
                arr[i] = ++start;
        }
    }
    public static ArrayList<Integer> KMP(String T, String P){
        ArrayList<Integer> answerlist = new ArrayList<>();
        Pi(P);
        int start = 0;
        for(int i=0;i<T.length();i++){
            while(start > 0 && T.charAt(i) != P.charAt(start))
                start = arr[start-1];
            if(T.charAt(i)  == P.charAt(start)){
                if(start == P.length()-1){
                    answerlist.add(i-P.length()+1);
                    start = arr[start];
                }
                else
                    start++;
            }
        }
        return answerlist;
    }
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String T = br.readLine();
        String P = br.readLine();
        arr = new int[P.length()];
        ArrayList<Integer> answerlist = KMP(T,P);
        StringBuffer sb = new StringBuffer();
        sb.append(answerlist.size()).append("\n");
        for(int i : answerlist)
            sb.append(i+1).append(" ");
        System.out.println(sb.toString());
    }
}