package com.company;
class Solution {
    public String solution(String new_id) {
        String tempanswer = new_id.toLowerCase();
        String tempanswer2 = "";
        for(int i=0;i<tempanswer.length();i++){
            char tempchar = tempanswer.charAt(i);
            if((tempchar>='a'&&tempchar<='z')||(tempchar>='0'&&tempchar<='9')||tempchar=='-'||tempchar=='.'||tempchar=='_'){
                tempanswer2 += tempchar;
            }
        }
        String tempanswer3 ="";
        boolean flag = false;
        for(int i=0; i<tempanswer2.length();i++){
            if(tempanswer2.charAt(i) == '.'){
                flag = true;
                continue;
            }
            else{
               if(flag){
                   tempanswer3 += '.';
                   tempanswer3 +=tempanswer2.charAt(i);
                   flag = false;
               }
               else
                   tempanswer3 += tempanswer2.charAt(i);
            }
        }
        String tempanswer4 ="";
        for(int i=0; i<tempanswer3.length();i++){
            if((i==0 && tempanswer3.charAt(i)=='.')|| (i==tempanswer3.length()-1 && tempanswer3.charAt(i) =='.'))
                continue;
            tempanswer4 += tempanswer3.charAt(i);
        }
        if(tempanswer4.isEmpty())
            tempanswer4 += "a";
        if(tempanswer4.length()>=16){
            tempanswer4 = tempanswer4.substring(0,15);
            if(tempanswer4.charAt(tempanswer4.length()-1) =='.')
                tempanswer4 = tempanswer4.substring(0,14);
        }
        else if(tempanswer4.length()<=2){
            while(tempanswer4.length()!=3){
                tempanswer4 += tempanswer4.charAt(tempanswer4.length()-1);
            }
        }
        String answer = tempanswer4;
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
        a.solution("123_.def");
    }
}
