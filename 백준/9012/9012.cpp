#include <iostream>
using namespace std;
int main() {
    int a = 0;
    string answer = "";
    cin >> a;
    int arry[2] = { 0,0 };
    for (int i = 0; i < a; i++) {
        string cur = "";
        cin >> cur;
        arry[0] = 0;
        arry[1] = 0;
        for (int j = 0; j < cur.size(); j++) {
            if (cur[j] == '(') {
                arry[0] += 1;
            }
            else if (cur[j] == ')') {
                arry[1] += 1;
            }
            if (arry[1] > arry[0]) {
                answer = "NO";
                break;
            }
        }
        if (answer == "NO") {
            cout << "NO" << endl;
            answer = "";
        }
        else if (arry[0] == arry[1]) {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}