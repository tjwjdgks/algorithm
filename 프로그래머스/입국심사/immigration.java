class Solution {
    public long solution(int n, int[] times) {
        long answer = 0;
        long low = 1;
        long high = (long)n* 1000000000;
        while(low<high){
            long mid = (low+high)/2;
            long totalcount=0;
            for(int i=0; i<times.length;i++){
                totalcount += mid/times[i];
                if(totalcount>n) break;
            }
            if(totalcount>=n)
                high = mid;
            else
                low = mid+1;
        }
        answer = low;
        return answer;
    }
}