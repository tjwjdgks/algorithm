import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class Main{
    // 분할 정복
    public static long getAnswer(long [] arr, int low, int high){
        if(low == high)
            return arr[low];
        int mid = (low+high)/2;
        long left = getAnswer(arr, low, mid);
        long right = getAnswer(arr, mid+1,high);
        long area = Math.max(left,right);

        area = Math.max(area,getTotal(arr,low,mid,high));
        return area;
    }
    public static long getTotal(long [] arr, int low, int mid, int high){
        int templow = mid;
        int temphigh = mid;
        long temparea = arr[mid];
        long tempheight = arr[mid];
        while(low<templow && temphigh<high){
            if(arr[templow-1]<arr[temphigh+1]){
                temphigh++;
                tempheight = Math.min(tempheight,arr[temphigh]);
            }
            else{
                templow--;
                tempheight = Math.min(tempheight,arr[templow]);
            }
            temparea = Math.max(temparea,(temphigh-templow+1)*tempheight);
        }
        while(low<templow){
            templow--;
            tempheight = Math.min(tempheight,arr[templow]);
            temparea = Math.max(temparea,(temphigh-templow+1)*tempheight);
        }
        while(temphigh < high){
            temphigh++;
            tempheight = Math.min(tempheight,arr[temphigh]);
            temparea = Math.max(temparea,(temphigh-templow+1)*tempheight);
        }
        return temparea;
    }
    // 스택
    public static long getAnswer(long[] arr){
        long total =0;
        Stack<Integer> stack = new Stack<>();
        for(int i=1; i<arr.length;i++){
            while(!stack.isEmpty()&& arr[stack.peek()]>=arr[i]){
                long height =  arr[stack.pop()];
                long width = stack.isEmpty()? i-1:i-1-stack.peek();
                total = Math.max(total, height*width);
            }
            stack.push(i);
        }
        while(!stack.isEmpty()){
            long height =arr[stack.pop()];
            long width = stack.isEmpty()?arr.length-1:arr.length-1-stack.peek();
            total = Math.max(total,height*width);
        }
        return total;
    }
    public static void main(String args[]) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        StringBuffer sb = new StringBuffer();
        while(true){
            long [] arr= Arrays.stream(bufferedReader.readLine().split(" ")).mapToLong(i->Long.parseLong(i)).toArray();

            if(arr[0] == 0 ) break;
            else{
                sb.append(getAnswer(arr,1,arr.length-1)+"\n");
            }
        }
        System.out.println(sb.toString());
    }
}
