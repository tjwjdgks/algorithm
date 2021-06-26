import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.joining;



public class Main {
    public static int[][] arr = new int[9][];
    public static StringBuffer sb  = new StringBuffer();
    public static boolean getRow(int y, int x, int val){
        for(int i=0;i<9; i++){
            if(arr[y][i] == val) {
                return false;
            }
        }
        return true;
    }
    public static boolean getCol(int y, int x, int val){

        for(int i=0; i<9; i++){
            if(arr[i][x] == val ) return false;
        }
        return true;
    }
    public static boolean getBox(int y, int x, int val){
        boolean check = true;
        int firstx = (x/3)*3;
        int firsty = (y/3)*3;
        for(int i = firsty; i<firsty+3;i++){
            for(int j = firstx; j<firstx+3;j++){
                if(arr[i][j] == val) return false;
            }
        }
        return check;
    }
    public static void sudoku(){
        for(int i=0; i<9; i++){
            for(int j=0; j<9;j++){
                if(arr[i][j] == 0){
                    for(int k=1;k<=9;k++){
                        if(getCol(i,j,k) && getRow(i,j,k) && getBox(i,j,k)){
                            arr[i][j] = k;
                            sudoku();
                            arr[i][j] = 0;
                        }
                    }
                    return;
                }
                if(i == 8 && j == 8){
                    for(int ii =0; ii<9;ii++){
                        for(int jj = 0; jj<9; jj++){
                            sb.append(arr[ii][jj]+" ");
                        }
                        sb.append("\n");
                    }
                    System.out.print(sb.toString());
                    System.exit(0);
                }
            }
        }
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for(int i=0; i<9;i++){
            arr[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(k->Integer.parseInt(k)).toArray();
        }
        sudoku();

    }
}