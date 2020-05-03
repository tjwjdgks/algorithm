#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> answerarry;
bool check[7];
void getAnswerArry(string number ,string &answer, int curnumber, int numcount,int targetnum) {
    if (numcount == targetnum) {
        return;
    }
    for (int i = 0; i < number.size(); i++) {
        if (check[i] == false) {
            string curnumbers =answer;
            answer = answer + number[i];
            check[i] = true;
            getAnswerArry(number,answer,i + 1, numcount+1,targetnum);
            if (answer.size() == targetnum) {
                answerarry.push_back(answer);
            }
            check[i] = false;
            answer = curnumbers;
        }
    }
    return;
}
int solution(string numbers) {
    int answer = 0;
    string an;
    for (int i = 1; i <= numbers.size();i++) {
        getAnswerArry(numbers, an, 0, 0, i);
    }
    vector<int> arry;
    for (int i = 0; i < answerarry.size(); i++) {
        int curnum = stoi(answerarry[i]);
        arry.push_back(curnum);
    }
    sort(arry.begin(), arry.end());
    int prenum = -1;
    for (int i = 0; i < arry.size(); i++) {
        int curnum = arry[i];
        if (prenum == curnum) {
            prenum = curnum;
            continue;
        }
        prenum = curnum;
        if (curnum == 2)answer += 1;
        else if (curnum > 2) {
            int j = 2;
            for (j; j< curnum; j++) {
                if (curnum % j == 0) break;
            }
            if (j == curnum) answer += 1;
        }
    }
    return answer;
    
}
int main() {
    string number = "011";
    string answer;
    getAnswerArry(number, answer, 0, 0, 3);
    do {
        for (int i = 0; i < answerarry.size(); i++) {
  
            cout << answerarry[i] << endl;

        }
    }whie(next_permutation(number.begin))
}