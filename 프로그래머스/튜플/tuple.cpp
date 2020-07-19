#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<int, int>m;
    bool check = false;
    string num = "";
    for (int i = 1; i < s.size() - 1; i++) {
        if (check && s[i] != '}') {
            if (s[i] >= '0' && s[i] <= '9') num += s[i];
            else if (s[i] == ',') {
                int temp = stoi(num);
                if (m.find(temp) == m.end()) m.insert(make_pair(temp, 1));
                else m.find(temp)->second++;
                num = "";
            }
        }
        else if (s[i] == '{') {
            check = true;
        }
        else if (s[i] == '}') {
            if (!num.empty()) {
                int temp = stoi(num);
                if (m.find(temp) == m.end()) m.insert(make_pair(temp, 1));
                else m.find(temp)->second++;
                num = "";
            }
            check = false;
        }
    }
    answer.resize(m.size());
    for (auto i = m.begin(); i != m.end(); i++) {
        answer[m.size() - i->second] = i->first;
    }
    return answer;
}