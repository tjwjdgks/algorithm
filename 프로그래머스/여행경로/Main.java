package com.company;
import java.util.*;
class Solution {
    public List<Stack<String>> result;
    String[][] tickets;
    public String[] solution(String[][] tickets) {
        result = new ArrayList<>();
        this.tickets = tickets;
        boolean[] visited = new boolean[tickets.length];
        Stack<String> st = new Stack<>();
        st.push("ICN");
        dfs(visited,st,0);
        if(result.size()>1){
            Collections.sort(result, new Comparator<Stack<String>>() {
                @Override
                public int compare(Stack<String> o1, Stack<String> o2) {
                    for(int i=0; i<o1.size();i++){
                        String s1 = o1.get(i);
                        String s2 = o2.get(i);
                        if(!s1.equals(s2)){
                            return s1.compareTo(s2);
                        }
                    }
                    return 0;
                }
            });
        }
        Stack<String> res = result.remove(0);
        String answer[] = new String[res.size()];
        for(int i=0; i<answer.length;i++){
            answer[i] = res.get(i);
        }
        return answer;
    }
    public void dfs(boolean[] visited, Stack<String> st, int len){
        if(len == tickets.length){
            Stack<String> res = new Stack<>();
            for (String s : st) {
                res.push(s);
            }
            result.add(res);
            return;
        }
        String arrive = st.peek();
        for(int i=0;i<tickets.length;i++){
            if(!visited[i] && arrive.equals(tickets[i][0])){
                st.push(tickets[i][1]);
                visited[i] = true;
                dfs(visited,st,len+1);
                visited[i] = false;
                st.pop();
            }
        }
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
       // a.solution(4,new int[][]{{0,1,1},{0,2,2},{1,2,5},{1,3,1},{2,3,8}}	);
    }
}
