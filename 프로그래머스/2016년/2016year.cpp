#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int datenum = 0;
    for (int i = 1; i < a; i++) {
        if (i == 2) {
            datenum += 29;
        }
        else if (i == 8) {
            datenum += 31;
        }
        else if (i % 2 == 1 && i < 9) {
            datenum += 31;
        }
        else if (i % 2 == 0 && i < 10) {
            datenum += 30;
        }
        else if (i % 2 == 1) {
            datenum += 30;
        }
        else {
            datenum += 31;
        }
    }
    datenum += b - 1;
    int dateday = datenum % 7;
    switch (dateday) {
    case 0:
        answer = "FRI";
        break;
    case 1:
        answer = "SAT";
        break;
    case 2:
        answer = "SUN";
        break;
    case 3:
        answer = "MON";
        break;
    case 4:
        answer = "TUE";
        break;
    case 5:
        answer = "WED";
        break;
    case 6:
        answer = "THU";
        break;

    }
    return answer;
}