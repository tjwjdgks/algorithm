import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static StringBuffer sb = new StringBuffer();
    static class Trie{
       ArrayList<Trie> arrayList;
       String data;
       public Trie(String s){
           data = s;
           arrayList = new ArrayList<>();
       }
       public void insert(String [] sarr , int idx){
           if(sarr.length == idx ) return;
           boolean check = false;
           for(Trie k : arrayList){
               if(k.data.equals(sarr[idx])){
                   k.insert(sarr,idx+1);
                   check = true;
               }
           }
           if(check == false){
               arrayList.add(new Trie(sarr[idx]));
               arrayList.get(arrayList.size()-1).insert(sarr,idx+1);
           }
       }
       public void print(int depth){
           Collections.sort(arrayList,(o1, o2) -> {
               return o1.data.compareTo(o2.data);
           });
           for(Trie k : arrayList){
               if(depth != 0){
                   for(int i=0;i<depth;i++){
                       sb.append("--");
                   }
               }
               sb.append(k.data).append("\n");
               k.print(depth+1);
           }
       }
    }

    public static void main(String args[]) throws IOException{
       BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
       int N = Integer.parseInt(br.readLine());
       Trie trie = new Trie("");
        for(int i=0;i<N;i++){
            String [] temparr = br.readLine().split(" ");
            trie.insert(temparr, 1);
        }
        trie.print(0);
        System.out.println(sb.toString());
    }
}