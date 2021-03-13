#include <iostream>

#include <algorithm>

#include <cstring> //memset

using namespace std;



int triangle[501][501]; //�ﰢ��

int cache[501][501];

int N;



int maxSum(int stage, int idx) //���� �ε���

{

    int& result = cache[stage][idx];

    if (result != -1)

        return result;

    if (stage == N - 1) //�� �Ʒ���

        return result = triangle[stage][idx];

    return result = max(maxSum(stage + 1, idx), maxSum(stage + 1, idx + 1)) + triangle[stage][idx]; //�� �� �� �� ū ������ �̵�

}



int main(void)

{

    cin >> N;

    if (N < 1 || N>500)

        exit(-1);



    for (int i = 0; i < N; i++)

        for (int j = 0; j <= i; j++)

            cin >> triangle[i][j];

    memset(cache, -1, sizeof(cache));

    cout << maxSum(0, 0) << endl;

    return 0;

}