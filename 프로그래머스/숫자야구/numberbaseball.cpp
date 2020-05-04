#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool check[9];
vector<vector<int>> totalarray;
void getArry(vector<int> & arry,int end){
    if (end == 3) {
        totalarray.push_back(arry);
        return;
    }
    for (int i = 0; i < 9; i++) {
        if (check[i]== false) {
            check[i] = true;
            arry.push_back(i + 1);
            getArry(arry, end + 1);
            arry.pop_back();
            check[i] = false;
        }
    }
}
int solution(vector<vector<int>> baseball) {
    int answer = 0;
    vector<int> arr;
    getArry(arr, 0);
    for (int i = 0; i < totalarray.size(); i++) {
        int j = 0;
        for (j; j < baseball.size(); j++) {
            int strike = baseball[j][1];
            int ball = baseball[j][2];
            int ballcur[3] = { baseball[j][0]/100 , (baseball[j][0]%100)/10 , baseball[j][0]%10 };
            int total = totalarray[i][0] * 100 + totalarray[i][1] * 10 + totalarray[i][2];
            int curstrike = 0;
            int curball = 0;
            for (int cur = 0; cur < 3; cur++) {
                if (totalarray[i][cur]==ballcur[cur]) {
                    curstrike += 1;
                }
                else if (totalarray[i][cur] == ballcur[(cur + 1) % 3] || totalarray[i][cur] == ballcur[(cur + 2) % 3]) {
                    curball += 1;
                }
            }
            if (strike != curstrike || ball != curball) {
                break;
            }
        }
        if (j == baseball.size()) answer += 1;
    }
    return answer;
}
int main() {
    vector<vector<int>> v{
        {123, 1, 1},{356, 1, 0},{327, 2, 0},{489, 0, 1}
    };
    int a = solution(v);
    cout << a;
}