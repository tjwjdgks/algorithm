#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<pair<int, int>> p;
    for (int i = 0; i < numbers.size(); i++) {
        string arr;
        string a = to_string(numbers[i]);
        int numsize = a.size();
        int re = 6 / a.size();
        int rest = 6 % a.size();
        for (int i = 0; i < re; i++) {
            arr += a;
        }
        arr += a.substr(0, rest);
        p.push_back(make_pair(stoi(arr),numsize));
    }
    sort(p.begin(), p.end(),greater<pair<int,int>>());
    for (int i = 0; i < p.size(); i++) {
        if (i == 0) {
            string aNum = to_string(p[i].first);
            if (stoi(aNum) == 0) {
                return answer="0";
            }
            answer += aNum.substr(0, p[i].second);
        }
        else {
            string aNum = to_string(p[i].first);
            answer += aNum.substr(0, p[i].second);
        }
    }
    
    return answer;
}
int main() {

}