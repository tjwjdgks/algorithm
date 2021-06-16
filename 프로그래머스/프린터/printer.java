import java.util.*;

class Pair{
    public int pos,value;
    public Pair(int pos, int value){
        this.pos = pos;
        this.value = value;
    }
}
class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        LinkedList<Pair> arr = new LinkedList<>();
        for(int i=0; i<priorities.length; i++){
            arr.add(new Pair(i,priorities[i]));
        }
        while(true){
            Pair curp = arr.poll();
            boolean check = true;
            for(Pair p : arr){
                if(p.value > curp.value){
                    check = false;
                    break;
                }
            }
            if(check == false){
                arr.add(curp);
            }
            else{
                answer++;
                if(curp.pos == location) break;
            }
        }
        return answer;
    }
}