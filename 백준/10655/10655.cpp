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
    v.push_back({ cx, cy });    // ó���� �������� �����ϱ� ���� ���� ����

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
        total += abs(cx - a) + abs(cy - b);
        cx = a, cy = b;            // �� �������� �̵��ϴ� ȿ���� ��
    }

    ans = total;    // ��� ������ �� �ִٸ� ���̰� �پ���� �ʴ´�.
    int skip = 0;    // ���� �� �ִ� �ִ��� �����ϴ� ����
    for (int i = 1; i < n - 1; i++) {    // �������� ������ ���� �ǳʶ� �� �����Ƿ�
        ss prev = v[i - 1], cur = v[i], next = v[i + 1];
        int dist = abs(prev.x - cur.x) + abs(prev.y - cur.y) + abs(cur.x - next.x) + abs(cur.y - next.y);    // �ǳʶ��� �ʴ� ����� ���� 
        int straight = abs(prev.x - next.x) + abs(prev.y - next.y);                                            // �ǳʶٴ� ����� ����

        skip = max(skip, dist - straight);
    }

    cout << total - skip;
}