package com.company;
class Solution {
    public int[] solution(long begin, long end) {
        int n = (int) (end - begin + 1);
        int[] road = new int[n];

        for (int i = 0; i < n; i++) {
            int cur = (int) begin + i;
            road[i] = getGD(cur);
        }

        if (begin == 1) road[0] = 0;
        return road;
    }

    private int getGD(int cur) {
        for (int i = 2; i <= Math.sqrt(cur); i++) {
            if (cur % i == 0 && (cur / i) < 10000000) {
                return cur / i;
            }
        }

        return 1;
    }
}
public class Main {
    public static void main(String[] args) {
        Solution a = new Solution();
    }
}
