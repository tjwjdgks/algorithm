class Solution {
    public int solution(int n, int[] money) {
        int answer = 0;
        int [] arr = new int[100001];
        arr[0] = 1;
        for(int i=0; i<money.length;i++){
            for(int j= money[i]; j<=n; j++){
                arr[j] = (arr[j] +arr[j-money[i]])%1000000007;
            }
        }
        answer = arr[n];
        return answer;
    }
}