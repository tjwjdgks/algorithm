#include <iostream>
#include <vector>
using namespace std;
int main() {
    int a = 0;
    cin >> a;
    int check = 0;
    vector<int> numarry;
    while (check < a) {
        string st;
        int num = 0;
        cin >> st;
        if (st == "push") {
            cin >> num;
            numarry.push_back(num);
        }
        else if (st == "pop") {
            if (numarry.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << numarry.back() << endl;
                numarry.pop_back();
            }
        }
        else if (st == "size") {
            cout << numarry.size() << endl;
        }
        else if (st == "empty") {
            if (numarry.empty()) {
                cout << 1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        else {
            if (numarry.empty()) {
                cout << -1 << endl;
            }
            else {
                cout << numarry.back() << endl;
            }
        }
        check++;
    }
}