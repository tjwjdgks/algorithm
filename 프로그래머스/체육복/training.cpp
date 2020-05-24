#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v(31, 1);
    for (int i = 0; i < lost.size(); i++) {
        v[lost[i]] -= 1;
    }
    for (int i = 0; i < reserve.size(); i++) {
        v[reserve[i]] += 1;
    }
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) {
            if (i == 1) {
                if (v[i + 1] == 2) {
                    answer += 1;
                    v[i + 1] -= 1;
                }
            }
            else if (i == n) {
                if (v[i - 1] == 2) {
                    answer += 1;
                    v[i - 1] -= 1;
                }
            }
            else {
                if (v[i - 1] == 2) {
                    answer += 1;
                    v[i - 1] -= 1;
                }
                else if (v[i + 1] == 2) {
                    answer += 1;
                    v[i + 1] -= 1;
                }
            }
        }
        else answer++;
    }
    return answer;
}
int main() {

}