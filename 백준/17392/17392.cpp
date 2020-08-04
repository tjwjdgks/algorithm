#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int appoint, day;
    vector<int> arry;
    cin >> appoint >> day;
    int totalhappy = 0;
    for (int i = 0; i < appoint; i++) {
        int temphappy;
        cin >> temphappy;
        totalhappy += temphappy + 1;
    }

    if (totalhappy >= day) cout << 0;
    else {
        int answer = 0;
        int batch = appoint + 1;
        int rest = day - totalhappy;
        int dividedbatch = rest / batch;
        int dividedrest = rest % batch;
        for (int i = 0; i < batch; i++) {
            int tempdividedbatch = dividedbatch;
            if (dividedrest > 0) {
                dividedrest--;
                tempdividedbatch++;
            }
            answer += tempdividedbatch * (tempdividedbatch + 1) * (2 * tempdividedbatch + 1) / 6;
        }
        cout << answer;
    }

}