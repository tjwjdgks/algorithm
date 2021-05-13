import java.util.*;
class Solution {
    public int minnum = Integer.MAX_VALUE;
    public int target;
    public int targetnum;
    public void getAnswer(int N, int count){
        if(count > 8)  return;
        if(target == N){
            minnum = Math.min(count,minnum);
            return;
        }
        int tempnum = targetnum;
        for(int i=0; i<8-count; i++){
            getAnswer(N+tempnum,count+i+1);
            getAnswer(N-tempnum,count+i+1);
            getAnswer(N*tempnum,count+i+1);
            getAnswer(N/tempnum,count+i+1);
            tempnum = tempnum*10 + targetnum;
        }

    }
    public int solution(int N, int number) {
        int answer = 0;
        target = number;
        targetnum = N;
        getAnswer(0,0);
        if(minnum == Integer.MAX_VALUE)
            answer = -1;
        else
            answer = minnum;
        return answer;
    }
}