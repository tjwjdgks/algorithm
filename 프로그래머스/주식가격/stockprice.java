import java.util.ArrayList;
import java.util.PriorityQueue;
class Pair implements Comparable<Pair>{
    public int key;
    public int value;
    Pair(int key,int value){
        this.key = key;
        this.value = value;
    }
    //우선순위 높은 것이 먼저 나옴
    // 자신 기준 ( < 일때 자신 기준이므로 key가 높은 것이 우선순위) 오름차순
    @Override
    public int compareTo(Pair o) {

        if(this.key < o.key) return 1;
        else if(this.key == o.key) return 0;
        else return -1;

    }
}
class Solution {
    public int[] solution(int[] prices) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        int [] answer = new int[prices.length];
        for(int i=0; i<prices.length;i++){
            while(!pq.isEmpty()){
                    Pair a = pq.peek();
                    if(a.key > prices[i]) {
                        pq.poll();
                        answer[a.value]=i-a.value;
                    }
                    else break;
            }
            pq.add(new Pair(prices[i],i));
        }
        while(!pq.isEmpty()){
            Pair temp = pq.poll();
            answer[temp.value] = prices.length-1-temp.value;
        }
        return answer;
    }
}
public class test{
    public static void main(String[] args){
        Solution a = new Solution();
         int[] c = a.solution(new int[]{1, 2, 3, 2, 3});
//       System.out.println(c);
    }
}
