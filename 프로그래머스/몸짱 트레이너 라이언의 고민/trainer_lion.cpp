#include<vector>
#include<algorithm>
using namespace std;

int getDistance(int, int, int);
int getFirst(int n, int distance) {
    int maxrange = 0;
    for (int i = 0; i < n; i++) {
        int curdistance = getDistance(i, distance, n);
        maxrange = max(maxrange, curdistance);
    }
    return maxrange;
}
int getDistance(int first, int distance, int n) {
    int res = 1;
    vector<vector<int>> array(n, vector<int>(n, 0));
    array[0][first] = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(i) + abs(first - j) <= distance) array[i][j] = 1;
        }
    }
    while (true) {
        int x, y;
        bool check = true;
        for (int i = 0; check && i < n; i++) {
            for (int j = 0; check && j < n; j++) {
                if (array[i][j] == 0) {
                    res++;
                    y = i; x = j; check = false; break;
                }
            }
        }
        if (!check) {
            array[y][x] = 2;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (array[i][j] == 0 && abs(i - y) + abs(j - x) <= distance) array[i][j] = 1;
                }
            }
        }
        else break;
    }
    return res;
}
int solution(int n, int m, vector<vector<int>> timetable) {
    int answer = 0;
    int maxnum = 0;
    for (int i = 600; i <= 1320; i++) {
        int curnum = 0;
        for (int j = 0; j < m; j++) {
            if (i >= timetable[j][0] && i <= timetable[j][1]) {
                curnum++;
            }
        }
        if (curnum > maxnum) {
            maxnum = curnum;
        }
    }
    if (maxnum <= 1) return 0;
    vector<int> gap(25, 0);
    for (int i = 0; i < 25; i++) {
        gap[i] = getFirst(n, i);
    }
    for (int i = 0; i < gap.size(); i++) {
        if (gap[i] >= maxnum) answer++;
    }
    return answer;
}