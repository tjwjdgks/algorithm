import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.regex.Pattern;

class Solution {
    public static int [] dy = {0,1,0,-1};
    public static int [] dx ={1,0,-1,0};
    static class Block{
        public int idx;
        public int [][] arr;
        public Block(int idx, int[][] arr) {
            this.idx = idx;
            this.arr = arr;
        }
    }

    public static ArrayList<Block> abstractBlock(int [][] board, int targetnum){
        ArrayList<Block> arr = new ArrayList<>();
        boolean [][] checkarr = new boolean[board.length][board[0].length];
        int numcount= 0;
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                if(board[i][j] == targetnum && checkarr[i][j] == false){
                    int minidx_y = i;
                    int minidx_x = j;
                    int maxidx_y = i;
                    int maxidx_x = j;
                    numcount++;
                    Queue<int[]> queue = new LinkedList<>();
                    checkarr[i][j] = true;
                    // y, x
                    queue.add(new int[]{i,j});
                    while(!queue.isEmpty()){
                        int [] curidx = queue.poll();
                        for(int k=0;k<4;k++){
                            int tempy = curidx[0] +dy[k];
                            int tempx = curidx[1] +dx[k];
                            if(tempy<board.length&& tempy>=0 && tempx>=0 && tempx<board[i].length){
                                if(checkarr[tempy][tempx] == false && board[tempy][tempx] == targetnum){
                                    checkarr[tempy][tempx] = true;
                                    queue.add(new int[]{tempy,tempx});

                                    minidx_x = Math.min(minidx_x,tempx);
                                    minidx_y = Math.min(minidx_y,tempy);
                                    maxidx_x = Math.max(maxidx_x,tempx);
                                    maxidx_y = Math.max(maxidx_y,tempy);
                                }
                            }
                        }
                    }
                    int [][] temparr = new int[maxidx_y-minidx_y+1][maxidx_x-minidx_x+1];
                    for(int start_y= minidx_y;start_y<=maxidx_y;start_y++){
                        for(int start_x = minidx_x;start_x<=maxidx_x;start_x++){
                            temparr[start_y-minidx_y][start_x-minidx_x] = board[start_y][start_x];
                        }
                    }
                    Block curblock = new Block(numcount,temparr);
                    arr.add(curblock);
                    if(targetnum ==1){
                        for(int k=0;k<3;k++){
                            temparr = rotate(temparr);
                            arr.add(new Block(numcount,temparr));
                        }
                    }
                }
            }
        }
        return arr;
    }
    public static int[][] rotate(int [][] temparr){
        int row = temparr.length;
        int col = temparr[0].length;
        int [][] rotate_arr = new int[col][row];
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                rotate_arr[j][row-1-i] = temparr[i][j];
            }
        }
        return rotate_arr;
    }
    public static int getAnswer(int [][] boardgame, ArrayList<Block> games, ArrayList<Block> tables){
        int answer = 0;
        int total_table_puzzle = tables.get(tables.size()-1).idx;
        boolean []check = new boolean[total_table_puzzle+1];
        for(Block block : games){
            for(int i=0;i<tables.size();i++){
                int curidx = tables.get(i).idx;
                if(check[curidx]) continue;
                int [][] curblock = block.arr;
                int [][] curtables = tables.get(i).arr;

                if(curblock.length == curtables.length && curblock[0].length == curtables[0].length){
                    int zerocount = 0;
                    boolean flag = false;
                    for(int start_y = 0; start_y<curblock.length;start_y++){
                        for(int start_x =0; start_x<curblock[0].length;start_x++){
                            if(curblock[start_y][start_x] == curtables[start_y][start_x]){
                                flag = true;
                                break;
                            }
                            if(curblock[start_y][start_x]  == 0)
                                zerocount++;
                        }
                    }
                    if(flag == false){
                        answer += zerocount;
                        check[curidx] = true;
                        break;
                    }
                }
            }
        }
        return answer;
    }
    public int solution(int[][] game_board, int[][] table) {
        int answer = -1;
        ArrayList<Block> game_puzzle = abstractBlock(game_board,0);
        ArrayList<Block> table_puzzle = abstractBlock(table,1);
        answer =getAnswer(  game_board,game_puzzle,table_puzzle);
        return answer;
    }
}