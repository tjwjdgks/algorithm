#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    for (int i = 0; i < heights.size(); i++) {
        int j;
        int cur = heights[i];
        for (j = i - 1; j >= 0; j--) {
            if (heights[j] > cur) {
                answer.push_back(j+1);
                break;
            }
        }
        if (j == -1) answer.push_back(0);
    }
    return answer;
}