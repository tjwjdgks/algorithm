#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> cores) {
    int answer = 0;
    int maxnumber = cores[0];
    int minnumber = cores[0];
    for (int i = 0; i < cores.size(); i++) {
        if (minnumber > cores[i]) minnumber = cores[i];
        if (maxnumber < cores[i])maxnumber = cores[i];
    }
    int maxnum = (maxnumber * n) / cores.size();
    int minnum = (minnumber * n) / cores.size();

    if (n - cores.size() <= 0) answer = n;
    else {
        while (maxnum - minnum >= 0) {
            int mid = (maxnum + minnum) / 2;
            int total = cores.size();
            int curwork = 0;

            for (int i = 0; i < cores.size(); i++) {
                total += mid / cores[i];
                if (mid % cores[i] == 0) curwork++;
            }
            if (n > total) minnum = mid + 1;
            else if (n <= total - curwork) maxnum = mid - 1;
            else {
                int count = 0;
                for (int i = 0; i < cores.size(); i++) {
                    if (mid % cores[i] == 0) count++;
                    if (count == n - (total - curwork)) return answer = i + 1;
                }
            }

        }
    }

    return answer;
}