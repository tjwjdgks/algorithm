#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> convertarry;
    unordered_map<string, string> um;
    for (int i = 0; i < record.size(); i++) {
        size_t first = record[i].find(' ');
        string keyword = record[i].substr(0, first);
        if (keyword == "Enter") {
            size_t second = record[i].find(' ', first + 1);
            string userid = record[i].substr(first + 1, second - (first + 1));
            string name = record[i].substr(second + 1);
            um[userid] = name;
            string alert = "0" + userid;
            convertarry.push_back(alert);
        }
        else if (keyword == "Change") {
            size_t second = record[i].find(' ', first + 1);
            string userid = record[i].substr(first + 1, second - (first + 1));
            string name = record[i].substr(second + 1);
            um[userid] = name;
        }
        else {
            string userid = record[i].substr(first + 1);
            string alert = "1" + userid;
            convertarry.push_back(alert);
        }
    }
    for (int i = 0; i < convertarry.size(); i++) {
        if (convertarry[i][0] == '0') {
            string userid = convertarry[i].substr(1);
            string name = um[userid];
            string alert = name + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
            answer.push_back(alert);
        }
        else {
            string userid = convertarry[i].substr(1);
            string name = um[userid];
            string alert = name + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
            answer.push_back(alert);

        }
    }
    return answer;
}