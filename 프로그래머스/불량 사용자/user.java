import java.util.regex.Pattern;
import java.util.*;

class Solution {
    private int bannedIdSize;
    private HashSet<HashSet<String>> result = new HashSet<>();
    
    public int solution(String[] user_id, String[] banned_id) {
        bannedIdSize = banned_id.length;
        int answer = 0;
        
        List<Set<String>> matchedIdList = new ArrayList<>();
        
        for (String bannedId : banned_id) {
            HashSet<String> userSet = new HashSet<>();
            for (String userId : user_id) {
                if (isMatchedId(userId, bannedId)) {
                    userSet.add(userId);
                }
            }
            
            matchedIdList.add(userSet);
        }
        
        int index = 0;
        dfs(index, matchedIdList, new HashSet<>());
        answer = result.size();
        
        return answer;
    }
    
    public void dfs(int index, List<Set<String>> matchedIdList, HashSet<String> userSet) {
        if (userSet.size() == bannedIdSize) {
            result.add(new HashSet<>(userSet));
            
            return;
        }
        
        for (String userId : matchedIdList.get(index)) {
            if (!userSet.contains(userId)) {
                userSet.add(userId);
                dfs(index + 1, matchedIdList, userSet);
                userSet.remove(userId);
            }
        }
    }
    
    public boolean isMatchedId(String userId, String bannedId) {
        String bannedPattern = bannedId.replace("*", ".");
        return Pattern.matches(bannedPattern, userId);
    }
}