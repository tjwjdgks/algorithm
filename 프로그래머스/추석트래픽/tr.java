import java.util.*;
// 부동소수점 오차 조심
//BigDecimal도 해결 방법 중 하나
class Solution {
    public int solution(String[] lines) {
        int answer = 0;
        int [][] arr= new int[lines.length][2];
        for(int i=0; i<lines.length;i++){
            String[] temp = lines[i].split(" |:|s");
            int hour = Integer.parseInt(temp[1])*60*60*1000;
            int min = Integer.parseInt(temp[2])*60*1000;
            int sec = Math.round(Float.parseFloat(temp[3])*1000);
            int gap = Math.round(Float.parseFloat(temp[4])*1000);
            arr[i][1] = hour+min+(int)sec;
            arr[i][0] = hour+min+(int)sec-(int)gap+1;
        }
        int maxcount =0;
        for(int i=0; i<arr.length;i++){
            int tempnum = arr[i][1] + 1000 -1;
            int tempcount = 1;
            for(int j=i+1; j<arr.length;j++){
                if(tempnum >= arr[j][0])
                    tempcount++;
            }
            maxcount = Math.max(tempcount,maxcount);
        }
        answer =maxcount;
        return answer;
    }
}
public class testtt {
    public static void main(String args[]){
       Solution a = new Solution();
       a.solution(new String[] {"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"});
    }
}