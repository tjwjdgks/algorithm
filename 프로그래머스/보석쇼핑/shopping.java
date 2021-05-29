import java.util.*;
class Solution {
    public int[] solution(String[] gems) {
        int[] answer = {};
        Set<String> s = new HashSet<>();
        for(int i=0;i<gems.length;i++){
            s.add(gems[i]);
        }
        if(s.size()==1)
            return new int[]{1,1};
        int start =0;
        int end = gems.length;
        int curstart = 0;
        int curend = 0;
        Map<String,Integer> m = new HashMap<>();
        Set<String> curs = new HashSet<>();
        String firsts = gems[0];
        curs.add(gems[0]);
        m.put(gems[0],1);
        for(int i=1; i<gems.length;i++){
            m.put(gems[i],m.getOrDefault(gems[i],0)+1);
            curs.add(gems[i]);
            curend++;
            if(firsts.equals(gems[i])){
                for(int j= curstart;j<=curend;j++){
                    if(m.get(gems[j])>1){
                        curstart++;
                        m.put(gems[j],m.get(gems[j])-1);
                    }
                    else{
                        firsts = gems[j];
                        break;
                    }
                }
            }
            if(curs.size() == s.size()){
                if(curend- curstart < end-start){
                    start = curstart;
                    end = curend;
                }
            }
        }
        answer = new int[2];
        answer[0] = start+1;
        answer[1] = end+1;
        return answer;
    }
}