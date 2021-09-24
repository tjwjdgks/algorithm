import java.util.*;
class Solution {
    public int[] solution(int[] weights, String[] head2head) {
        int N = weights.length;
        int[] answer = new int[N];
        // 승률, 몸무게> 이긴 회수, 몸무게, 번호
        double[][] infoArr = new double[N][4];
        
        for(int i=0;i<N;i++){
            int total =0;
            int fightcount = 0;
            int weightOverWinCount = 0;
            int weight = weights[i];
            for(int j=0;j<N;j++){
                char c = head2head[i].charAt(j);
                if(c == 'L'){
                    fightcount++;
                }
                else if(c=='W'){
                    fightcount++;
                    total++;
                    if(weights[j]>weight)
                        weightOverWinCount++;
                }
            }
            if(fightcount ==0)
                infoArr[i][0] = 0;
            else
                infoArr[i][0] = (double)total/fightcount;
            infoArr[i][1] = weightOverWinCount;
            infoArr[i][2] = weight;
            infoArr[i][3] = i;
        }
        Arrays.sort(infoArr,(o1,o2)->{
            if(o1[0] == o2[0]){
                if(o1[1] == o2[1]){
                    if(o1[2] == o2[2]){
                        return Double.compare(o1[3],o2[3]);
                    }
                    return Double.compare(o2[2],o1[2]);
                }
                return Double.compare(o2[1],o1[1]);
            }
            return Double.compare(o2[0],o1[0]);
        });
        
        for(int i=0;i<N;i++){
            answer[i] = (int) infoArr[i][3]+1;
        }
        return answer;
    }
}