package com.company;


class Solution {
    public String getAnswer(String s){
        if(s.isEmpty())
            return "";
        int uright =0;
        int uleft =0;
        boolean check = true;
        boolean checku = false;
        String u ="";
        String v ="";
        for(int i=0; i<s.length();i++){
           if(checku){
               v += s.charAt(i);
           }
           else{
               u += s.charAt(i);
               if(s.charAt(i) == '(')
                   uleft++;
               else{
                   uright++;
               }
               if(uright > uleft)
                   check = false;
               if(uright !=0 && uright == uleft)
                   checku = true;
           }
        }
        if(check){
            return u+= getAnswer(v);
        }
        else{
            String temp ="";
            String cur ="";
            for(int i=1;i<u.length()-1;i++){
                if(u.charAt(i) == '(')
                    temp += ')';
                else
                    temp += '(';
            }
            return cur += '(' + getAnswer(v) + ')' + temp;
        }
    }
    public String solution(String p) {
        String answer = getAnswer(p);
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
       // a.solution(new int[]{3, 30, 34, 5, 9	});
    }
}
