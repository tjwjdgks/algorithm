#include <string>
#include <vector>
#include <deque>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int, int>> d;
    for (int i = 0; i < priorities.size(); i++) {
        d.push_back(make_pair(i, priorities[i]));
    }
    int count = 0;
    while (true) {
        count++;
        int maxtemp = 0;
        for (int i = 0; i < d.size(); i++) {
            if (maxtemp < d[i].second)
                maxtemp = d[i].second;
        }
        for (int i = 0; i < d.size();) {
            if (maxtemp == d[i].second) {
                if (location == d[i].first) {
                    answer = count;
                }
                else {
                    d.pop_front();
                }
                break;
            }
            else {
                int a = d[i].first;
                int b = d[i].second;
                d.pop_front();
                d.push_back(make_pair(a, b));
            }
        }
        if (answer != 0) {
            break;
        }

    }
    return answer;
}