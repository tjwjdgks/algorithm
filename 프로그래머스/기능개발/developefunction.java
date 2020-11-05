import java.util.*;
class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i=0; i<progresses.length;){
            int tmpnum = 100-progresses[i];
            int value = tmpnum/speeds[i];
            int rest = tmpnum%speeds[i];
            if(rest ==0) value++;
            boolean check = true;
            int tempindex = i;
            int task =0;
            for(int j=i;j<progresses.length;j++){
                progresses[j] += speeds[j]*value;
                if(progresses[j]>=100&&check){
                    tempindex++;
                    task++;
                }
                else check=false;
            }
            arr.add(task);
            i = tempindex;
        }
        int[] answer = new int[arr.size()];
        for(int i=0; i<answer.length;i++)
            answer[i]= arr.get(i);
        return answer;
    }
}
public class test{
    public static void main(String[] args){
        Solution a = new Solution();
        int[] arr = {93, 30, 55};
        int[] arr2 = {1, 30, 5};
        int[] b = a.solution(arr,arr2);
    }
}
