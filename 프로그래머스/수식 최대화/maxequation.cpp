#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long calculate(string text, char sign) {
    long long num;
    vector<long long> numarry;
    string temp;
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == sign) {
            numarry.push_back(stoll(temp));
            temp = "";
        }
        else temp += text[i];
    }
    numarry.push_back(stoll(temp));

    num = numarry[0];
    for (int i = 1; i < numarry.size(); i++) {
        if (sign == '*') num *= numarry[i];
        else if (sign == '+') num += numarry[i];
        else num -= numarry[i];
    }
    return num;
}
long long solution(string expression) {
    long long answer = 0;
    char totalsign[3] = { '*','-','+' };
    vector<char> signpermutation;
    for (int i = 0; i < 3; i++) {
        size_t pos;
        pos = expression.find(totalsign[i]);
        if (pos != string::npos) signpermutation.push_back(totalsign[i]);
    }
    sort(signpermutation.begin(), signpermutation.end());
    do {
        string tempexpression = expression;
        for (int i = 0; i < signpermutation.size() - 1; i++) {
            string next;
            string current;

            string tempnum;
            bool check = false;
            bool check2 = false;
            for (int j = 0; j < tempexpression.size(); j++) {

                if (tempexpression[j] == '*' || tempexpression[j] == '-' || tempexpression[j] == '+') {
                    if (j == 0 || tempexpression[j - 1] == '*' || tempexpression[j - 1] == '+') {
                        tempnum = "-" + tempnum;
                    }
                    else {

                        if (tempexpression[j] == signpermutation[i]) {
                            current += tempnum;
                            current += tempexpression[j];
                            tempnum = "";
                            check = true;
                        }
                        else {
                            if (check == true) {
                                current += tempnum;
                                long long calculatednum = calculate(current, signpermutation[i]);
                                next += to_string(calculatednum);
                                next += tempexpression[j];
                                current = "";
                                tempnum = "";
                                check = false;
                            }
                            else {
                                next += tempnum;
                                next += tempexpression[j];
                                tempnum = "";
                            }

                        }
                    }
                }
                else {
                    tempnum += tempexpression[j];
                }
            }
            if (!current.empty()) {
                current += tempnum;
                long long calculatednum = calculate(current, signpermutation[i]);
                next += to_string(calculatednum);
            }
            else next += tempnum;
            tempexpression = next;
        }
        long long finalnum = calculate(tempexpression, signpermutation[signpermutation.size() - 1]);
        answer = max(abs(finalnum), answer);
    } while (next_permutation(signpermutation.begin(), signpermutation.end()));
    return answer;
}