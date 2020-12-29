import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
class G implements Comparable<G> {
    public int firstval;
    public int secondval;
    public int value=0;
    public G(int firstval,int secondval, int value){
        this.firstval = firstval;
        this.secondval = secondval;
        this.value = value;
    }
    public G(int firstval,int secondval){
        this.firstval = firstval;
        this.secondval = secondval;
    }
    @Override
    public int compareTo(G o) {
       return this.value-o.value;
    }
}
class Solution {
    public int []indexarr;
    public int solution(int[][] land, int height) {
        int answer = 0;
        Queue<G> q = new LinkedList<>();
        int [][]checkarr = new int[land.length][land.length];
        //시계
        int[] dx = {0,1,0,-1};
        int[] dy = {1,0,-1,0};
        int count = 0;
        for(int i=0; i<land.length;i++){
            for(int j=0; j<land.length;j++){
                if(checkarr[i][j]== 0){
                    count++;
                    checkarr[i][j] = count;
                    q.add(new G(i,j,land[i][j]));
                    while(!q.isEmpty()){
                        G g = q.poll();
                        for(int k=0;k<4; k++){
                            int ty = g.firstval + dy[k];
                            int tx = g.secondval + dx[k];
                            if(tx>=0 && tx<land.length && ty>=0 && ty<land.length && checkarr[ty][tx]==0){
                                if(Math.abs(land[ty][tx] - g.value)<=height){
                                    checkarr[ty][tx] = count;
                                    q.add(new G(ty,tx,land[ty][tx]));
                                }
                            }
                        }
                    }
                }
            }
        }
        Queue<G> sg = new PriorityQueue<>();
        for(int i=0; i<checkarr.length;i++){
            for(int j=0; j<checkarr.length; j++){
               for(int k=0;k<4;k++){
                   int ty = i+dy[k];
                   int tx = j+dx[k];
                   if(tx>=0 && tx<checkarr.length && ty>=0&& ty<checkarr.length && checkarr[i][j] != checkarr[ty][tx]){
                       sg.add(new G(checkarr[i][j],checkarr[ty][tx],Math.abs(land[i][j] - land[ty][tx])));
                   }
               }
            }
        }
        indexarr = new int[count+1];
        int checkcount =0;
        for(int i=0; i<indexarr.length;i++){
            indexarr[i] = checkcount;
            checkcount++;
        }
        checkcount =0;
        while(!sg.isEmpty()){
            G tg = sg.poll();
            int fi = find(tg.firstval);
            int si = find(tg.secondval);
            if(fi == si) continue;
            bind(fi,si);
            answer += tg.value;
        }
        return answer;
    }
    public int find(int a){
        if(indexarr[a] == a)
            return a;
        return indexarr[a] = find(indexarr[a]);
    }
    public void bind(int a, int b){
        if(a<b)
            indexarr[b] =a;
        else
            indexarr[a] = b;
    }
    public void test(){
        indexarr = new int[]{0,1,1,1,4,5,5,5};
        int a = find(1);
        int b = find(5);
        bind(a,b);
        int c= find(7);
        int d = find(5);
    }
}
public class test{
    public static void main(String[] args){
        Solution a = new Solution();
        int s = a.solution(new int[][]{{10, 11, 10, 11}, {2, 21, 20, 10}, {1, 20, 21, 11}, {2, 1, 2, 5}},1);
//       System.out.println(c);
        System.out.println(s);
    }
}
