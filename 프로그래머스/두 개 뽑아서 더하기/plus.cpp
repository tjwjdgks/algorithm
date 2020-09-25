#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    sort(numbers.begin(), numbers.end());
    set<int> s;
    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            int tempnum = numbers[i] + numbers[j];
            if (s.find(tempnum) == s.end()) s.insert(tempnum);
        }
    }
    for (auto i = s.begin(); i != s.end(); i++) {
        answer.push_back(*i);
    }
    sort(answer.begin(), answer.end());
    return answer;
}