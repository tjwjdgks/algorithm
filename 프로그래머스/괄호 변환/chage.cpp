#include <iostream>
#include <string>
#include <vector>

using namespace std;

string getAnswer(string a) {
    if (a == "") return "";
    string u = "";
    string v = "";
    bool check = true;
    bool checku = false;
    int left = -1;
    int right = -1;
    for (int i = 0; i < a.length(); i++) {
        if (checku) {
            v += a[i];
        }
        else {
            u += a[i];
            if (a[i] == '(') {
                left += 1;
            }
            else {
                right += 1;
            }
            if (right > left) {
                check = false;
            }
            if (left != -1 && right != -1 && left == right) {
                checku = true;
            }
        }
    }
    if (check) {
        return u += getAnswer(v);
    }
    else {
        string temp = "";
        string cur = "";
        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(') {
                temp += ")";
            }
            else {
                temp += "(";
            }
        }
        return cur += "(" + getAnswer(v) + ")" + temp;
    }
}
string solution(string p) {
    string answer = getAnswer(p);
    return answer;
}