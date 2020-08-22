#include <vector>
#include <iostream>
#include <set>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    set<int> numarry;
    numarry.insert(2);
    for (int i = 3; i < 50001; i++) {
        int j;
        for (j = 2; j < i; j++) {
            if (i % j == 0) break;
        }
        if (j == i) numarry.insert(j);
    }
    for (int i = 0; i < nums.size() - 2; i++) {
        for (int j = i + 1; j < nums.size() - 1; j++) {
            for (int z = j + 1; z < nums.size(); z++) {
                int tempnum = nums[i] + nums[j] + nums[z];
                if (numarry.find(tempnum) != numarry.end())answer++;
            }
        }
    }
    return answer;
}