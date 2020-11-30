import java.util.*;
class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        int leftsize =0;
        int rightsize = people.length-1;
        Arrays.sort(people);
        while(leftsize<=rightsize){
            int curlimit = limit;
            curlimit -= people[rightsize];
            rightsize--;
            if(curlimit >= people[leftsize])
                leftsize++;
            answer++;
        }
        return answer;
    }
}
public class test{
    public static void main(String[] args){
        Solution a = new Solution();
        int z = a.solution(new int[]{70,80,50},100);
        System.out.println(z);
    }
}
