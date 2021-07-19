import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.*;

public class Main {
    public static int [] arr = new int[10001];
    public static StringBuffer sb = new StringBuffer();
    public static void getAnswer(int idx, int last){
        if(idx>last) return;
        int root = arr[idx];
        int right = last;
        while(root<arr[right])
            right--;
        //left
        getAnswer(idx+1,right);
        getAnswer(right+1,last);
        sb.append(root).append("\n");
    }
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str;
        int count =0;
        while((str = br.readLine())!=null && !str.equals("")){
            if(str.equals("")) break;
            arr[count++] = Integer.parseInt(str);
        }
        getAnswer(0,count-1);
        System.out.println(sb.toString());
    }
}