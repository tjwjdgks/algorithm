import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Main {
    public static int minNum = Integer.MAX_VALUE , numInt;
    public static Set<String> set = IntStream.range(0,10).mapToObj(String::valueOf).collect(Collectors.toSet());

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        numInt = Integer.parseInt(br.readLine());
        minNum = Math.min(minNum,Math.abs(numInt-100));

        if("0".equals(br.readLine()) == false){
            Arrays.stream(br.readLine().split(" ")).forEach(i->set.remove(i));
        }
        if(set.isEmpty() == false){
            find("");
        }
        System.out.println(minNum);
    }
    public static void find(String num){
        for(String s : set){
            String curnum = num+s;
            minNum = Math.min(minNum,Math.abs(numInt - Integer.parseInt(curnum))+curnum.length());

            if(curnum.length()<6)
                find(curnum);
        }
    }
}