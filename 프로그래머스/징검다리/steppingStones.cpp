#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> rocks,int distance,int mid,int n) {
    int checks = 0, prev = 0;
    for (int i = 0; i < rocks.size(); i++) {
        if (rocks[i] - prev < mid) {
            checks += 1;
        }
        else {
            prev = rocks[i];
        }
    }
    if (distance - rocks.back()<mid) {
        checks += 1;
    }
    
    return checks <= n;
}
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    sort(rocks.begin(), rocks.end());
    int low = 1, high = distance, mid;
    while (low + 1 < high) {
        mid = (low + high) / 2;
        if (check(rocks, distance, mid, n)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    if (check(rocks, distance, low, n)) {
        answer = low;
    }
    else answer = high;
    return answer;
}