#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

vector<pair<int, int>> arr;
pair<int, int> trace[100003];
int lis[100003];
bool visit[500003];

stack<int> s;

int _lower_bound(int start, int end, int target)
{
    int mid;

    while (start < end)
    {
        mid = (start + end) / 2;

        if (lis[mid] < target)
            start = mid + 1;
        else
            end = mid;
    }
    return end + 1;
}
int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int idx, val;
        scanf("%d %d", &idx, &val);

        // 인덱스와 값을 넣어준다.
        arr.push_back({ idx, val });
        // 인덱스가 생긴 부분은 true로 설정
        visit[idx] = true;
    }

    // 인덱스 기준으로 정렬
    sort(arr.begin(), arr.end());


    // lis 알고리즘을 적용한다.
    // 이때 실제 인덱스를 알아야 하기에 lis 추적 알고리즘까지 접목한다.
    int pLis = 0, pArr = 1;

    lis[pLis] = arr[0].second;
    trace[0].first = 0;
    trace[0].second = arr[0].first;

    vector<int> vc;

    while (pArr < n)
    {
        if (lis[pLis] < arr[pArr].second)
        {
            lis[++pLis] = arr[pArr].second;

            trace[pArr].first = pLis;
            trace[pArr].second = arr[pArr].first;
        }
        else
        {
            int ans = _lower_bound(0, pLis, arr[pArr].second);
            lis[ans - 1] = arr[pArr].second;

            trace[pArr].first = ans - 1;
            trace[pArr].second = arr[pArr].first;
        }

        pArr++;
    }

    printf("%d\n", n - (pLis + 1));

    int len = vc.size();
    int t = pLis;

    // lis 추적 코드
    for (int i = n - 1; i >= 0; i--)
        if (trace[i].first == t)
        {
            s.push(trace[i].second);
            t--;
        }

    // 스택에 쌓인 인덱스를 false로 바꿔준다. 
    while (!s.empty())
    {
        visit[s.top()] = false;
        s.pop();
    }

    // 정답이 되는 인덱스를 출력
    for (int i = 0; i <= 500000; i++)
        if (visit[i])
            printf("%d\n", i);

    return 0;
}