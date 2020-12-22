import java.util.*;
class Pair{
    Integer key;
    Integer value;
    public Pair(Integer key, Integer value){
        this.key= key;
        this.value = value;
    }
}
class Solution {
    public int solution(int[] priorities, int location) {
        int answer =0;
        Queue<Pair> queue = new LinkedList<>();
        for(int i=0; i<priorities.length;i++){
            Pair temp = new Pair(i,priorities[i]);
            queue.add(temp);
        }
        while(true){
            Pair tempP = queue.poll();
            boolean check = true;
            for(Pair i : queue){
                if(i.value > tempP.value){
                    check = false;
                    break;
                }
            }
            if(check && tempP.key == location){
                answer++;
                break;
            }
            else if(check){
                answer++;
            }
            else{
                queue.add(tempP);
            }
        }
        return answer;
    }
}
public class test{
    public static void main(String[] args){
        Solution a = new Solution();
        int c = a.solution(new int[]{1,1,9,1,1,1},0);
        System.out.println(c);
    }
}
