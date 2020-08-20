#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

long long solution(vector<vector<int> > land, int P, int Q)
{
    long long answer = -1;
    int N = land.size();
    vector<long long > v;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            v.push_back(land[i][j]);
    sort(v.begin(), v.end());

    long long temp = 0;
    for (int i = 0; i < v.size(); i++)
        temp += (v[i] - v[0]) * Q;

    answer = temp;

    for (int i = 1; i < v.size(); i++) {

        int down = i;
        int up = v.size() - i;

        temp += down * (v[i] - v[i - 1]) * P;
        temp -= up * (v[i] - v[i - 1]) * Q;
        if (answer > temp)
            answer = temp;
    }
    return answer;
}