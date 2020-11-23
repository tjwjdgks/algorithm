import java.util.*;
class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        Stack<Integer> s = new Stack<>();
        for(int x=0; x< moves.length; x++){
            for(int y=0;y<board.length;y++){
                if(board[y][moves[x]-1] !=0){
                    if(!s.empty() && s.peek()==board[y][moves[x]-1]){
                        s.pop();
                        answer +=2;
                    }
                    else
                        s.push(board[y][moves[x]-1]);
                    board[y][moves[x]-1] =0;
                    break;
                }
            }
        }
        return answer;
    }
}
public class test{
    public static void main(String[] args){

    }
}
