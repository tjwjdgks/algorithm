import java.util.*;
class Solution {
    public int[] solution(int N, int[] stages) {
        int[] answer = new int[N];
        int [] arr= new int[N+1];
        double[][] temparr= new double[N][2];
        for(int i= 0;i<stages.length;i++){
            arr[stages[i]-1] +=1;
        }
        double totalcount =stages.length;
        for(int i=0; i<arr.length-1;i++){
            if(totalcount == 0 )
                temparr[i][1] = i+1;
            else{
                temparr[i][0] = arr[i]/totalcount;
                temparr[i][1] = i+1;
                totalcount -= arr[i];
            }   
        }
        Arrays.sort(temparr,(o1,o2) ->{
            if(o1[0] == o2[0])
                return Double.compare(o1[1],o2[1]);
            else
                return Double.compare(o2[0],o1[0]);
        });
        for(int i=0;i<temparr.length;i++){
            answer[i] = (int)temparr[i][1];
        }
        return answer;
    }
}