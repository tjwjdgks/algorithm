import java.util.*;
import java.util.stream.Stream;

class Solution {
    public Map<String, ArrayList<Integer>> allinfo = new HashMap<>();
    public int[] solution(String[] info, String[] query) {
        for(String i : info){
            String [] curarr = i.split(" ");
            insertInfo("",curarr,0);
        }
        int[] answer = new int[query.length];
        int count = 0;
        List<String> list = new ArrayList<>(allinfo.keySet());
        for(int i=0; i<list.size(); i++) {
            List<Integer> scoreList = allinfo.get(list.get(i));
            Collections.sort(scoreList);
        }
        for(String i : query){
            String after = i.replaceAll(" and ","");
            String [] curarr = after.split(" ");
            int mininumNumber = Integer.parseInt(curarr[1]);
            answer[count] = searchAndGetSize(curarr[0],mininumNumber);
            count++;
        }
        return answer;
    }
    // right 값보다 클 수 있으므로 target.size()
    // 따라서 return target.size() - right가 아닌 target.size() - left // left로 return 기준 잡는 이유 left+1 이므로 left가 변경
    // 이분 탐색 left로 기준을 잡는다 right 기준은 mid가 짝수 홀수에 영향을 받기 때문에 좋지 않음
    public int searchAndGetSize(String s, int mininumNumber){
        ArrayList<Integer> target = allinfo.get(s);
        int left  = 0;
        int right = target.size();
        while(left<right){
            int mid = (left+right)/2;
            if(target.get(mid)>=mininumNumber){
                right = mid;
            }
            else{
                left = mid+1;
            }
        }
        return target.size()-left;
    }
    public void insertInfo(String s, String[] arr, int depth){
        if(depth == 4){
            int curnum = Integer.parseInt(arr[depth]);
            if(allinfo.containsKey(s)){
                allinfo.get(s).add(curnum);
            }
            else{
                ArrayList<Integer> currow = new ArrayList<>();
                currow.add(curnum);
                allinfo.put(s,new ArrayList<>(List.of(curnum)));
            }
            return;
        }
        insertInfo(s+"-",arr,depth+1);
        insertInfo(s+arr[depth],arr,depth+1);
    }
}