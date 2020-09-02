#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


struct node {
    int value;
    string title;
};
bool compare(node a, node b) {
    return a.value < b.value;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    map<string, vector<node>> m;
    for (int i = 0; i < files.size(); i++) {
        bool checkf = false;
        bool checks = false;
        string head = "";
        string nums = "";
        int count = 0;
        for (int j = 0; j < files[i].size(); j++) {
            if (files[i][j] >= '0' && files[i][j] <= '9') {
                if (count > 5) checks = true;
                else {
                    checkf = true;
                    count++;
                    if (!checks) nums += files[i][j];
                }
            }
            else {
                if (!checkf) {
                    if (files[i][j] >= 'A' && files[i][j] <= 'Z')
                        head += tolower(files[i][j]);
                    else head += files[i][j];
                }
                else checks = true;
            }
        }
        node temp = { stoi(nums),files[i] };
        m[head].push_back(temp);
    }
    int a = 0;
    for (pair<string, vector<node>> cur : m) {
        stable_sort(cur.second.begin(), cur.second.end(), compare);
        for (int i = 0; i < cur.second.size(); i++)
            answer.push_back(cur.second[i].title);
    }
    return answer;
}