#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long long solution(int w, int h) {
    std::setprecision(18);
    long long answer = 1;
    answer = (long long)w * h;
    for (int i = 0; i < w; i++) {
        double first, last;
        first = floor(((double)h * i / w));
        last = ceil(((double)h * (i + 1) / w));
        long long gap = (long long)(last - first);
        answer -= gap;
    }
    return answer;
}