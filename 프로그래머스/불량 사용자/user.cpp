#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
bool arrays[9];
int total;
set<string> s;
void CountNum(int n, int dep, string temp, vector<vector<int>> banned_array) {
    if (n == dep) {
        sort(temp.begin(), temp.end());
        s.insert(temp);
        return;
    }
    int result = 0;
    int i;
    for (i = 0; i < banned_array[n].size(); i++) {
        if (arrays[banned_array[n][i]] == false) {
            arrays[banned_array[n][i]] = true;
            CountNum(n + 1, dep, temp + to_string(banned_array[n][i]), banned_array);
            arrays[banned_array[n][i]] = false;
        }
    }
    return;
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<int>> banned_array(banned_id.size());
    for (int i = 0; i < banned_id.size(); i++) {
        for (int z = 0; z < user_id.size(); z++) {
            if (banned_id[i].size() == user_id[z].size()) {
                int j = 0;
                for (j = 0; j < banned_id[i].size(); j++) {
                    if (banned_id[i][j] != user_id[z][j] && banned_id[i][j] != '*') {
                        break;
                    }
                }
                if (j == banned_id[i].size()) {
                    banned_array[i].push_back(z);
                }
            }
        }
    }

    CountNum(0, banned_id.size(), "", banned_array);
    answer = s.size();
    return answer;
}