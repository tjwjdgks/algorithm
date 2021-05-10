import java.util.*;
class Solution {
    public String solution(String new_id) {
        String answer = "";
        String step1 = new_id.toLowerCase();
        String step2 = step1.replaceAll("[^a-z0-9\\-_.]","");
        String step3 = step2.replaceAll("\\.{2,}",".");
        if(step3.charAt(0) == '.') step3 = step3.substring(1);
        if(!step3.isEmpty() && step3.charAt(step3.length()-1) == '.') step3 = step3.substring(0,step3.length()-1);
        if(step3.isEmpty())
            step3 +='a';
        if(step3.length()>=16)
            step3 = step3.substring(0,15);
        if(step3.charAt(step3.length()-1) == '.')
            step3 = step3.substring(0,step3.length()-1);
        if(step3.length()<=2){
            while(step3.length()<3){
                step3 += step3.charAt(step3.length()-1);
            }
        }
        return step3;
    }
}
public class test {
    public static void main(String args[]){
        String a= "...!@BaT#*..y.abcdef-ghijklm";
        String t = a.toLowerCase();
        System.out.println(t);
        String tt =t.replaceAll("[^a-z0-9_\\-.]","");
        System.out.println(tt);
        String ttt = tt.replaceAll("\\.{2,}",".");
        System.out.println(ttt);

        System.out.println("test");
    }
}
