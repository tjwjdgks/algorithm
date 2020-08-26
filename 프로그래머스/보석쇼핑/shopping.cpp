#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    unordered_map<string, int> arry;
    set<string> gemsarry;
    queue<string> firstarry;
    for (int i = 0; i < gems.size(); i++) {
        if (gemsarry.find(gems[i]) == gemsarry.end())gemsarry.insert(gems[i]);
    }
    int gemssize = gemsarry.size();
    int minqsize = 100000;
    int start = 0;
    int temp = 0;
    int end = 0;
    for (int i = 0; i < gems.size(); i++) {
        if (arry[gems[i]] == 0) arry[gems[i]] = 1;
        else arry[gems[i]] += 1;
        firstarry.push(gems[i]);
        while (1) {
            if (arry[firstarry.front()] > 1) {
                arry[firstarry.front()] -= 1;
                firstarry.pop();
                temp++;
            }
            else break;
        }
        if (arry.size() == gemsarry.size() && firstarry.size() < minqsize) {
            minqsize = firstarry.size();
            start = temp;
        }
    }
    answer.push_back(start + 1);
    answer.push_back(start + minqsize);
    return answer;
}