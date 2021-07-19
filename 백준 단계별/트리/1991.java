import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.*;

public class Main {
    public static ArrayList<ArrayList<Integer>> arr;
    public static String answer1 = "";
    public static String answer2 = "";
    public static String answer3 = "";
    public static void lf(int start){
        if(start == -1 ) return;
        ArrayList<Integer> curarr = arr.get(start);
        answer1+= (char)(start+'A');
        lf(curarr.get(0));
        lf(curarr.get(1));
    }
    public static void mf(int start){
        if(start == -1 ) return;
        ArrayList<Integer> curarr = arr.get(start);
        mf(curarr.get(0));
        answer2+= (char)(start+'A');
        mf(curarr.get(1));
    }
    public static void rf(int start){
        if(start == -1 ) return;
        ArrayList<Integer> curarr = arr.get(start);
        rf(curarr.get(0));
        rf(curarr.get(1));
        answer3+= (char)(start+'A');
    }
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        arr = new ArrayList<>(N);
        for(int i=0;i<N;i++)
            arr.add(new ArrayList<>());
        StringTokenizer st;
        for(int i=0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            int from = st.nextToken().charAt(0)-'A';
            int left = st.nextToken().charAt(0)-'A';
            int right = st.nextToken().charAt(0)-'A';
            if(left>0)
                arr.get(from).add(left);
            else
                arr.get(from).add(-1);
            if(right>0)
                arr.get(from).add(right);
            else
                arr.get(from).add(-1);
        }
        lf(0);
        mf(0);
        rf(0);
        System.out.println(answer1);
        System.out.println(answer2);
        System.out.println(answer3);
    }
}