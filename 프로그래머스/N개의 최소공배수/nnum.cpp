#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    unordered_map<int, int> um;
    for (int i = 0; i < arr.size(); i++) {
        vector<pair<int, int>> temp;
        int tempnum = arr[i];
        int first = 2;
        int count = 0;
        while (tempnum != 1) {
            if (tempnum % first == 0) {
                tempnum = tempnum / first;
                count++;
            }
            else {
                if (count > 0) temp.push_back(make_pair(first, count));
                first++;
                count = 0;
            }
        }
        if (count > 0) temp.push_back(make_pair(first, count));

        for (int i = 0; i < temp.size(); i++) {
            auto index = um.find(temp[i].first);
            if (index != um.end()) {
                if (index->second < temp[i].second)index->second = temp[i].second;
            }
            else um.insert(temp[i]);
        }
    }

    for (pair<int, int> nums : um) {
        answer *= pow(nums.first, nums.second);
    }
    return answer;
}