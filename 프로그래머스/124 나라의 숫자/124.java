class Solution {
    public String solution(int n) {
        String answerR = "";
        while (n != 0) {
            n--;
            int rest = n % 3;
            n /= 3;
            switch (rest) {
                case 0:
                    answerR += '1';
                    break;
                case 1:
                    answerR += '2';
                    break;
                case 2:
                    answerR += '4';
                    break;
            }
        }
        String answer = new StringBuffer(answerR).reverse().toString();
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
