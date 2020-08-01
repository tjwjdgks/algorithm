#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

string solution(string s) {
    string nums;
    vector<int> arry;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            int num = stoi(nums);
            arry.push_back(num);
            nums = "";
        }
        else {
            nums += s[i];
        }
    }
    arry.push_back(stoi(nums));
    sort(arry.begin(), arry.end());
    return to_string(arry[0]) + " " + to_string(arry[arry.size() - 1]);
}