#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MXN = 1e5;
struct st {
    int x, y1, y2, t;
};
vector<int> idx;
int lt[MXN * 8], ct[MXN * 8];
int l_b(int s, int e, int goal)
{
    int h = s, t = e, m;
    while (h <= t)
    {
        m = (h + t) / 2;
        if (idx[m] == goal) break;
        else if (idx[m] < goal) h = m + 1;
        else t = m - 1;
    }
    return m;
}
void update(int h, int l, int r, int gl, int gr, int x) {
    if (r < gl || gr < l) return;
    if (gl <= l && r <= gr) ct[h] += x;
    else {
        update(h * 2 + 1, l, (l + r) / 2, gl, gr, x);
        update(h * 2 + 2, (l + r) / 2 + 1, r, gl, gr, x);
    }
    if (ct[h]) lt[h] = idx[r + 1] - idx[l];
    else lt[h] = l ^ r ? lt[h * 2 + 1] + lt[h * 2 + 2] : 0;
}
bool compare(const st& i, const st& j) { return i.x < j.x; }

long long solution(vector<vector<int> > rectangles)
{
    int n = rectangles.size();
    vector<st> line;
    line.resize(2 * n);
    idx.resize(2 * n);
    long long res = 0;
    for (int i = 0, x1, x2, y1, y2; i < n; i++) {
        x1 = rectangles[i][0];
        y1 = rectangles[i][1];
        x2 = rectangles[i][2];
        y2 = rectangles[i][3];
        line[i] = { x1,y1,y2,1 };
        line[i + n] = { x2,y1,y2,-1 };
        idx[i] = y1;
        idx[i + n] = y2;
    }
    sort(line.begin(), line.end(), compare);
    sort(idx.begin(), idx.end());
    int e = 0;
    for (int i = 1; i < 2 * n; ++i)
        if (idx[i] != idx[i - 1])
            idx[++e] = idx[i];
    e++;
    for (int i = 0; i < 2 * n; i++) {
        if (i) res += (long long)lt[0] * (line[i].x - line[i - 1].x);
        update(0, 0, e - 1, l_b(0, e, line[i].y1), l_b(0, e, line[i].y2) - 1, line[i].t);
    }
    return res;
}
