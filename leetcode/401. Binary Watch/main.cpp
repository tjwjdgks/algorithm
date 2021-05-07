#include <algorithm>
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> answer;
        vector<int> arr = { 1,2,4,8,16,32,1,2,4,8 };
        vector<int> arrindex;
        for (int i = 0; i < turnedOn; i++) {
            arrindex.push_back(0);
        }
        for (int i = turnedOn; i < 10; i++) {
            arrindex.push_back(1);
        }
        do {
            int hour = 0;
            int min = 0;
            for (int i = 0; i < 6; i++) {
                if (arrindex[i] == 0)
                    min += arr[i];
            }
            for (int i = 6; i < 10; i++) {
                if (arrindex[i] == 0)
                    hour += arr[i];
            }
            if (hour <= 11 && min <= 59) {
                string tempanswer = to_string(hour) + ":";
                if (min < 10) {
                    tempanswer += '0';
                }
                tempanswer += to_string(min);
                answer.push_back(tempanswer);
            }

        } while (next_permutation(arrindex.begin(), arrindex.end()));
        return answer;
    }
};