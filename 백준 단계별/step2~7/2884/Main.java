import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input = br.readLine();
        StringTokenizer stringTokenizer = new StringTokenizer(input);
        int H = Integer.parseInt(stringTokenizer.nextToken());
        int M = Integer.parseInt(stringTokenizer.nextToken());
        int maxnum = 24*60;
        int modifiednum = H*60 + M - 45;
        if(modifiednum<0)
            modifiednum = maxnum + modifiednum;
        int curH = modifiednum/60;
        int curM = modifiednum%60;
        System.out.println(curH +" "+curM);
    }
}