import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String args[]) throws IOException  {
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       int num = Integer.parseInt(br.readLine());
       br.close();
       char grade;
       if(num>= 90) {
           grade = 'A';
       }
       else if(num>=80 && num <90) {
           grade = 'B';
       }
       else if(num<80 && num >=70) {
           grade = 'C';
       }
       else if(num<70 && num >=60) {
           grade = 'D';
       }
       else {
           grade ='F';
       }
       System.out.println(grade);
    }
}