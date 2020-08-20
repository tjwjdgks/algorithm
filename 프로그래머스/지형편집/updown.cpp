#include <algorithm>
#include<vector>
using namespace std;
long long getTotal(vector<vector<int>>& land, int num, int p, int q) {
    long long total = 0;
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[i].size(); j++) {
            int tempnum = num - land[i][j];
            if (tempnum < 0) {
                total += (long long)abs(tempnum) * q;
            }
            else {
                total += (long long)tempnum * p;
            }
        }
    }
    return total;
}
long long solution(vector<vector<int> > land, int P, int Q) {
    long long answer = -1;
    int N = land.size();
    int minnum = land[0][0];
    int maxnum = land[0][0];
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land[i].size(); j++) {
            minnum = min(minnum, land[i][j]);
            maxnum = max(maxnum, land[i][j]);
        }
    }
    while (minnum <= maxnum) {
        int midnum = (minnum + maxnum) / 2;
        if (minnum == maxnum)break;
        long long totalmidf = 0;
        long long totalmidl = 0;
        totalmidf = getTotal(land, midnum, P, Q);
        totalmidl = getTotal(land, midnum + 1, P, Q);
        if (totalmidf < totalmidl) maxnum = midnum;
        else minnum = midnum + 1;
    }
    answer = getTotal(land, minnum, P, Q);
    return answer;
}