
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arry[2001][2001];
vector<int>leftarr;
vector<int> rightarr;
int getAnswer(int left, int right, int leftsize, int rightsize) {
    if (left == leftsize || right == rightsize) {
        return 0;
    }
    if (arry[left][right] != 0) {
        return arry[left][right];
    }
    if (leftarr[left] > rightarr[right]) {
        int curnum = getAnswer(left, right + 1, leftsize, rightsize) + rightarr[right];
        arry[left][right] = curnum;
        return curnum;
    }
    else {
        int curnum = max(getAnswer(left + 1, right + 1, leftsize, rightsize), getAnswer(left + 1, right, leftsize, rightsize));
        arry[left][right] = curnum;
        return curnum;
    }

}
int solution(vector<int> left, vector<int> right) {
    leftarr = left;
    rightarr = right;
    int answer = getAnswer(0, 0, left.size(), right.size());
    return answer;
}