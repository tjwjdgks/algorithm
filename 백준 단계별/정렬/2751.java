import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.stream.Collectors;


public class Main {
    public static void quickSort(int arr[], int left, int right){
        int pivot = (left+right)/2;
        int pivotnum = arr[pivot];
        int curleft  = left;
        int curright = right;
        while(curleft<=curright){
            while(arr[curleft]< pivotnum)
                curleft++;
            while(arr[curright]>pivotnum)
                curright--;
            if(curleft<=curright){
                if(curleft != curright){
                    int temp = arr[curleft];
                    arr[curleft] = arr[curright];
                    arr[curright] = temp;
                }
                curleft++;
                curright--;
            }
        }
        if(left<curright)
            quickSort(arr,left,curright);
        if(right>curleft)
            quickSort(arr,curleft,right);
    }
    public static int []mergearr;
    public static void MergeSort(int arr[], int left, int right){
        int mid = (right+left)/2;
        if(left<right){         
            MergeSort(arr,left,mid);
            MergeSort(arr,mid+1,right);
            Merge(arr,left,mid, right);
        }
    }
    public static void Merge(int arr[],int left, int mid, int right){
        int curlefts = left;
        int currights = mid+1;
        int count = left;
        while(curlefts<=mid && currights<=right){
            if(arr[curlefts]<=arr[currights]){
                mergearr[count++]= arr[curlefts];
                curlefts++;
            }
            else{
                mergearr[count++]= arr[currights];
                currights++;
            }
        }
        if(curlefts == mid+1){
            while(currights<=right){
                mergearr[count++] = arr[currights];
                currights++;
            }
        }
        else if(currights== right+1){
            while(curlefts<=mid){
                mergearr[count++] = arr[curlefts];
                curlefts++;
            }
        }
        for(int i = left;i<=right;i++){
            arr[i] = mergearr[i];
        }
    }
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int [] arr = new int[N];
        mergearr = new int[N];
        for(int i=0; i<N; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        MergeSort(arr,0,arr.length-1);
        StringBuilder sb = new StringBuilder();
        for(int i : arr)
            sb.append(i+"\n");
        System.out.println(sb.toString());
    }
}
