import java.util.*;
class Solution {
    public int[] solution(int[] numbers) {
        HashSet<Integer> set = new HashSet<Integer>();
        for(int i=0; i<numbers.length-1;i++){
            for(int j=0; j<numbers.length;j++){
                if(i==j) continue;
                int curnum = numbers[i]+numbers[j];
                set.add(curnum);
            }
        }
        Integer[] arr = new Integer[set.size()];
        set.toArray(arr);
        int answer[] = Arrays.stream(arr).mapToInt(Integer::intValue).toArray();
        Arrays.sort(answer);
        return answer;
    }
}
public class test{
    public static void main(String[] args){

    }
}
