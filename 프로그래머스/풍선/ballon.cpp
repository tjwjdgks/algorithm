#include <string>
#include <vector>
#include <limits.h>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> l_min(a.size(), INT_MAX);
    vector<int> r_min(a.size(), INT_MAX);

    for (int i = 1; i < a.size(); i++) {
        l_min[i] = min(l_min[i - 1], a[i - 1]);
    }

    for (int i = a.size() - 2; i >= 0; i--) {
        r_min[i] = min(r_min[i + 1], a[i + 1]);
    }
    for (int i = 1; i < a.size() - 1; i++) {
        if (l_min[i] < a[i] && r_min[i] < a[i]) continue;
        else answer++;
    }
    return answer + 2;
}