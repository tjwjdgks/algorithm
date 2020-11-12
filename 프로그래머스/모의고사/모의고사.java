import java.util.*;
class Solution {
    public int[] solution(int[] answers) {
        ArrayList<Integer> answer = new ArrayList<>();
        int[] studentArr = new int[3];
        int[][] answerArr = {{1,2,3,4,5},
                            {2,1,2,3,2,4,2,5},
                            {3,3,1,1,2,2,4,4,5,5}};
        int i=0;
        while(i<answers.length){
            for(int j=0;j<3;j++){
                int rest = i % answerArr[j].length;
                if(answers[i] == answerArr[j][rest])
                    studentArr[j]++;
            }
            i++;
        }
        int maxval=0;
        for(int k=0; k<studentArr.length;k++){
            if(maxval<studentArr[i])
                maxval = studentArr[i];
        }
        for(int k=0; k<studentArr.length;k++){
            if(maxval == studentArr[i])
                answer.add(k);
        }
       return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}
public class test{
    public static void main(String[] args){
        Solution a = new Solution();
        int[] arr = {1,2,3,4,5};
        a.solution(arr);

    }
}
