import java.util.*;
class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;
        Map<String,Integer> s1 = new HashMap<>();
        Map<String,Integer> s2 = new HashMap<>();
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();
        for(int i=0; i<str1.length()-1;i++){
            if(Character.isLetter(str1.charAt(i)) && Character.isLetter(str1.charAt(i+1))){
                String cur1 = str1.charAt(i) + "" + str1.charAt(i+1);
                s1.put(cur1,s1.getOrDefault(cur1,0)+1);
            }
        }
        for(int i=0; i<str2.length()-1;i++){
              if(Character.isLetter(str2.charAt(i)) && Character.isLetter(str2.charAt(i+1))){
                String cur2 = str2.charAt(i) + "" + str2.charAt(i+1);
                s2.put(cur2,s2.getOrDefault(cur2,0)+1);
            }
        }
        if(s1.isEmpty() && s2.isEmpty())
            return 65536;
        int lower = 0;
        int total = 0;
        for(String a : s1.keySet()){
            if(s2.get(a) != null){
                lower += Math.min(s1.get(a),s2.get(a));
            }
            total += s1.get(a);
        }   
        for(String a: s2.keySet()){
            total += s2.get(a);
        }
        int interact = lower;
        int union = total-lower;
        answer = 65536*interact/union;
        return answer;
    }
}
