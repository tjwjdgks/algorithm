import java.io.*;
import java.util.Scanner;

public class Main {
    public static long getCount(long num, long maxnum, long minnum){
        long firstnum = num;
        long count  = 0;
        while(firstnum<=maxnum){
            count += maxnum/firstnum - (maxnum-minnum)/firstnum- minnum/firstnum;
            firstnum *=num;
        }
        return count;

    }
    public static void main(String args[]) throws IOException{
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        long m = scanner.nextLong();
        long count2 =0;
        long count5 = 0;
        count2 = getCount(2,n,m);
        count5 = getCount(5,n,m);
        
        System.out.println(Math.min(count2,count5));
    }
}
