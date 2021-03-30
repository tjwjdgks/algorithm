package com.company;
import java.util.*;
class Solution {
    class Pair{
        String first;
        int second;
        Pair(String first, int second){
            this.first = first;
            this.second = second;
        }
    }
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(begin,0));
        boolean []check = new boolean[words.length];
        while(!q.isEmpty()){
            Pair temp = q.peek();
            if(target.equals(temp.first)){
                answer = temp.second;
                break;
            }
            q.poll();
            for(int i=0;i<words.length;i++){
                if(check[i]) continue;
                int checknum =0;
                for(int j=0; j<words[i].length();j++){
                    if(temp.first.charAt(j) != words[i].charAt(j)){
                        checknum++;
                        if(checknum>1) break;
                    }
                }
                if(checknum == 1){
                    q.add(new Pair(words[i],temp.second+1));
                    check[i] = true;
                }
            }
        }
        return answer;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
        a.solution("hit","cog",new String[]{"hot", "dot", "dog", "lot", "log", "cog"});
    }
}
