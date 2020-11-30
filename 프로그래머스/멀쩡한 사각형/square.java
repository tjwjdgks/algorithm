import java.math.BigInteger;

class Solution {
    public long solution(int w, int h) {
        long total = (long)w*h;
        long answer = total - ((long)w+ (long)h - (BigInteger.valueOf(w).gcd(BigInteger.valueOf(h)).longValue()));
        return answer;
    }
}
public class test{
    public static void main(String[] args){
        Solution a = new Solution();

    }
}
