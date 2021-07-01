import java.awt.desktop.SystemSleepEvent;
import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.joining;



public class Main {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int cases = Integer.parseInt(br.readLine());
        StringBuffer sb = new StringBuffer();
        for(int i=0; i<cases;i++){
            HashMap<String, Integer> m = new HashMap<>();
            int clothnum = Integer.parseInt(br.readLine());
            for(int j= 0; j<clothnum;j++){
                String s = br.readLine();
                String types = s.substring(s.indexOf(' ')+1);
                m.put(types,m.getOrDefault(types,0)+1);
            }
            int count =1;
            for(int val : m.values()){
                count *= val+1;
            }
            count -=1;
            sb.append(count+"\n");
        }
        System.out.println(sb.toString());
    }
}