#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    int startindex = p - 1;
    int endindex = startindex;
    for (int i = 0; i < t; i++) {
        endindex += m;
    }
    string temp = "0";
    int startnum = 1;
    while (temp.size() < endindex) {
        int tempnum = startnum;
        string curnumarry = "";
        while (true) {
            if (tempnum == 0) break;
            else {
                int curnum = tempnum % n;
                if (curnum >= 10) {
                    int alpha = curnum - 10 + 'A';
                    curnumarry += alpha;
                }
                else curnumarry += to_string(curnum);
                tempnum /= n;
            }
        }
        reverse(curnumarry.begin(), curnumarry.end());
        temp += curnumarry;
        startnum++;
    }
    for (int i = 0; i < t; i++) {
        answer += temp[startindex];
        startindex += m;
    }
    return answer;
}