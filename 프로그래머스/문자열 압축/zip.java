package com.company;
class Solution {
    public int solution(String s) {
        int answer = 0;
        answer = s.length();
        for(int i=1; i<=s.length()/2;i++){
            int count =1;
            String compareS = s.substring(0,i);
            String newS = "";
            for(int j=i;j<s.length();j+=i){
                if(j+i>= s.length()) {
                    String curS = s.substring(j);
                    if (curS.equals(compareS)) {
                        count++;
                        newS += Integer.toString(count) + compareS;
                    } else {
                        if (count == 1)
                            newS += compareS + curS;
                        else
                            newS += Integer.toString(count) + compareS + curS;
                    }
                }
                else{
                    String curS = s.substring(j,j+i);
                    if(curS.equals(compareS)) count++;
                    else{
                        if(count==1){
                            newS += compareS;
                            compareS = curS;
                        }
                        else{
                            newS += Integer.toString(count)+compareS;
                            compareS = curS;
                            count =1;
                        }
                    }
                }
            }
            answer = (answer > newS.length()) ? newS.length() : answer;
        }
        return answer;
    }
}
public class Main {

    public static void main(String[] args) {
        Solution a = new Solution();
    }
}
