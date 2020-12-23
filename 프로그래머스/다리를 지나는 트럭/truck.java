import java.util.Queue;
import java.util.LinkedList;
class Pair{
    Integer time;
    Integer weight;
    public Pair(Integer time, Integer weight){
        this.time = time;
        this.weight = weight;
    }
}
class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        Queue<Pair> q = new LinkedList<>();
        int limit=0;
        int time=0;
        for(int i=0; i<truck_weights.length;){
            if(limit+truck_weights[i]<=weight){
                time++;
                q.add(new Pair(time+bridge_length,truck_weights[i]));
                limit = limit + truck_weights[i];
                i++;
                continue;
            }
            else{
                boolean check = true;
                while(limit+truck_weights[i]>weight){
                    Pair tempV = q.poll();
                    if(tempV.time <= time){
                        limit -= tempV.weight;
                        if(check) time++;
                        check = false;
                        continue;
                    }
                    limit -= tempV.weight;
                    time = tempV.time;
                }
                time -=1;
            }
        }
        while(!q.isEmpty()){
            Pair rest = q.poll();
            answer = rest.time;
        }
        return answer;
    }
}
public class test{
    public static void main(String[] args){
        Solution a = new Solution();
        int c = a.solution(5,5,new int[]{2, 2, 2, 2, 1, 1, 1, 1, 1});
        System.out.println(c);
    }
}
