#include <string>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> q;
    int qsize = 0;
    for (int i = 0; i < cities.size(); i++) {
        int j;
        string temp = "";
        for (j = 0; j < cities[i].size(); j++) {
            temp += tolower(cities[i][j]);
        }
        for (j = 0; j < q.size(); j++) {
            if (q[j] == temp) {
                answer += 1;
                q.erase(q.begin() + j);
                q.push_back(temp);
                break;
            }
        }
        if (j == q.size()) {
            if (qsize < cacheSize) {
                q.push_back(temp);
                answer += 5;
                qsize++;
            }
            else {
                if (cacheSize != 0) {
                    q.pop_front();
                    q.push_back(temp);
                }
                answer += 5;
            }
        }
    }
    return answer;
}