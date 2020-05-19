#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a = 0;
    int answer = 0;
    cin >> a;
    vector<int> arry;
    for (int i = 0; i < a; i++) {
        int curnum = 0;
        cin >> curnum;
        if (curnum == 0) {
            answer -= arry.back();
            arry.pop_back();
        }
        else {
            arry.push_back(curnum);
            answer += curnum;
        }
    }
    cout << answer;
}