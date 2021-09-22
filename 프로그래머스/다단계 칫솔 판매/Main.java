package com.company;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

import java.util.*;
class Solution {
    public int [] indexArr;
    public int [] total;
    public Map<String, Integer> map= new HashMap<>();
    public void dfs(int idx, int money){
        if(money/10 == 0 || idx == 0){
            total[idx] += money;
            return;
        }
        int rest = money - money/10;
        total[idx] += rest;
        dfs(indexArr[idx],money/10);
    }
    public int[] solution(String[] enroll, String[] referral, String[] seller, int[] amount) {
        indexArr = new int[enroll.length+1];
        total = new int[enroll.length+1];
        int indexnum = 0;
        map.put("-",indexnum++);
        for(int i=0;i<enroll.length;i++){
            map.put(enroll[i],indexnum++);
        }
        for(int i=0; i<referral.length;i++){
            indexArr[i+1] = map.get(referral[i]);
        }
        for(int i=0; i<seller.length;i++){
            dfs(map.get(seller[i]),100*amount[i]);
        }
        int[] answer = new int[enroll.length];
        for(int i=1;i< total.length;i++){
            answer[i-1] = total[i];
        }

        return answer;
    }
}