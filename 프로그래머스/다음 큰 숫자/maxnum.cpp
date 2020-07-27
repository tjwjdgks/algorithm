#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
    deque<int> numarry;
    while (n != 0) {
        numarry.push_front(n % 2);
        n /= 2;
    }
    int i = 0;
    for (i = numarry.size() - 1; i > 0; i--) {
        if (numarry[i] == 1 && numarry[i - 1] == 0) {
            numarry[i] = 0;
            numarry[i - 1] = 1;
            sort(numarry.begin() + i, numarry.end());
            break;
        }
    }
    if (i == 0) {
        numarry[i] = 0;
        numarry.push_front(1);
        sort(numarry.begin() + 1, numarry.end());
    }
    int binarytoten = 1;
    for (int j = numarry.size() - 1; j >= 0; j--) {
        answer += binarytoten * numarry[j];
        binarytoten *= 2;
    }
    return answer;
}