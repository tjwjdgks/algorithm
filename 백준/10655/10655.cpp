#include <bits/stdc++.h>

using namespace std;

struct ss {
    int y, x;
};

int n, m;

vector<ss> v;

int main() {
    int ans = 0;
    int cy, cx;
    int total = 0;

    cin >> n;
    cin >> cx >> cy;
    v.push_back({ cx, cy });    // 처음에 시작점을 세팅하기 위해 따로 빼줌

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
        total += abs(cx - a) + abs(cy - b);
        cx = a, cy = b;            // 그 다음으로 이동하는 효과를 줌
    }

    ans = total;    // 모두 일직선 상에 있다면 길이가 줄어들지 않는다.
    int skip = 0;    // 줄일 수 있는 최댓값을 저장하는 변수
    for (int i = 1; i < n - 1; i++) {    // 시작점과 마지막 점은 건너뛸 수 없으므로
        ss prev = v[i - 1], cur = v[i], next = v[i + 1];
        int dist = abs(prev.x - cur.x) + abs(prev.y - cur.y) + abs(cur.x - next.x) + abs(cur.y - next.y);    // 건너뛰지 않는 경우의 길이 
        int straight = abs(prev.x - next.x) + abs(prev.y - next.y);                                            // 건너뛰는 경우의 길이

        skip = max(skip, dist - straight);
    }

    cout << total - skip;
}