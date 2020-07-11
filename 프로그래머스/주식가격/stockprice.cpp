#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    priority_queue < pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
    pq.push(make_pair(prices[0], 0));
    for (int i = 1; i < prices.size(); i++) {
        while (!pq.empty()) {
            int tempvalue = pq.top().first;
            int tempindex = pq.top().second;
            if (tempvalue > prices[i]) {
                int curindex = i - tempindex;
                if (curindex < 1) {
                    answer[tempindex] = 1;
                }
                else answer[tempindex] = curindex;
                pq.pop();
            }
            else {
                break;
            }
        }
        pq.push(make_pair(prices[i], i));
    }
    while (!pq.empty()) {
        int tempvalue = pq.top().first;
        int tempindex = pq.top().second;
        pq.pop();
        answer[tempindex] = prices.size() - tempindex - 1;
    }
    return answer;
}