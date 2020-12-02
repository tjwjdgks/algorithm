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

        // �ε����� ���� �־��ش�.
        arr.push_back({ idx, val });
        // �ε����� ���� �κ��� true�� ����
        visit[idx] = true;
    }

    // �ε��� �������� ����
    sort(arr.begin(), arr.end());


    // lis �˰����� �����Ѵ�.
    // �̶� ���� �ε����� �˾ƾ� �ϱ⿡ lis ���� �˰������ �����Ѵ�.
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

    // lis ���� �ڵ�
    for (int i = n - 1; i >= 0; i--)
        if (trace[i].first == t)
        {
            s.push(trace[i].second);
            t--;
        }

    // ���ÿ� ���� �ε����� false�� �ٲ��ش�. 
    while (!s.empty())
    {
        visit[s.top()] = false;
        s.pop();
    }

    // ������ �Ǵ� �ε����� ���
    for (int i = 0; i <= 500000; i++)
        if (visit[i])
            printf("%d\n", i);

    return 0;
}