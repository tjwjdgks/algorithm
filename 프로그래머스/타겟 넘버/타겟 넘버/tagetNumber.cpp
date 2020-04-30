#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int totalnumber = 1;
    for (int i = 0; i < numbers.size(); i++) {
        totalnumber *= 2;
    }
    for (int i = 0; i < totalnumber; i++) {
        int curnumber = totalnumber / 2;
        vector<int> numArry;
        int number = i;
        for (int j = 0; j < numbers.size(); j++) {
            if (number == 0) {
                numArry.push_back(0);
            }
            else {
                int numIndex = number / curnumber;
                number = number % curnumber;
                curnumber = curnumber / 2;
                numArry.push_back(numIndex);
            }
        }
        int targetnum = 0;
        for (int j = 0; j < numArry.size(); j++) {
            if (numArry[j] == 0) {
                targetnum += numbers[j];
            }
            else targetnum -= numbers[j];
        }
        if (targetnum == target) {
            answer += 1;
        }
    }
    return answer;
}
int main() {
    vector<int> numbers = { 1, 1, 1, 1, 1 };
    int a = solution(numbers, 3);
    cout << a;
}