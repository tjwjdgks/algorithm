import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        double [][] edges = new double[N+1][2];
        StringTokenizer st;
        for(int i=0;i<N;i++){
            st= new StringTokenizer(br.readLine());
            double x = Double.parseDouble(st.nextToken());
            double y = Double.parseDouble(st.nextToken());
            edges[i][0]  =x;
            edges[i][1]  =y;
        }
        edges[N][0] =edges[0][0];
        edges[N][1]  = edges[0][1];
        double area = 0;
        for(int i=0;i<N;i++){
            area += (edges[i][0] + edges[i+1][0])*(edges[i][1] - edges[i+1][1]);
        }
        area = Math.abs(area)/2;
        System.out.printf("%.1f",area);
    }
}