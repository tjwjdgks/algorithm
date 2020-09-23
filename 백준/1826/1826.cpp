#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int n, End, oil;
vector<pair<int, int> > v;
priority_queue<int> pq;

int main()
{
    cin.tie(0);
    scanf("%d", &n);
    int a, b;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        v.push_back({ a, b });
    }
    sort(v.begin(), v.end());
    scanf("%d %d", &End, &oil);
    int ans = 0;
    int here = 0;
    for (int i = 0; i < v.size(); i++) {
        while (!pq.empty() && here + oil < v[i].first)
        {
            oil += pq.top();
            ++ans;
            pq.pop();
        }
        oil = oil - (v[i].first - here);

        if (oil < 0) {

            break;
        }
        here = v[i].first;
        pq.push(v[i].second);
    }
    while (!pq.empty() && here + oil < End)
    {
        oil += pq.top();
        ++ans;
        pq.pop();
    }
    printf("%d\n", here + oil >= End ? ans : -1);
    return 0;
}
