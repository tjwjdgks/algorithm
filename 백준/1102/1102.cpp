#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring> //memset
using namespace std;
const int MAX = 16 + 1;
const int INF = 987654321;
int N, P;
string currentState;
int bit = 1 << MAX;
int fixCost[MAX][MAX];
int cache[MAX][1 << MAX]; //�� ��° ������, ������ ��������
//��Ʈ �� 1 ���� ��
int countSetBits(int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}
int minCost(int idx, int curState)
{
    //���� ����
    if (countSetBits(curState) - 1 >= P)
        return 0;
    int& result = cache[idx][curState];
    if (result != -1)
        return result;
    result = INF;
    for (int i = 0; i < N; i++)
        if ((curState & (1 << i)) == 0) //���� �����Ҹ� ã��
        {
            int nextState = curState | (1 << i); //�ش� �����Ҹ� �״ٰ� ����
            for (int j = 0; j < N; j++)
                if ((nextState & (1 << j))) //�ش� �����Ҹ� Ų ���� �ܰ�� �̵�
                    result = min(result, fixCost[idx][i] + minCost(j, nextState));
        }
    return result;
}
int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> fixCost[i][j];
    cin >> currentState;
    for (int i = 0; i < currentState.size(); i++)
        if (currentState[i] == 'Y')
            bit |= (1 << i);
    cin >> P;
    if (P == 0)
        cout << 0 << endl;
    else
    {
        memset(cache, -1, sizeof(cache));
        int result = INF;
        for (int i = 0; i < N; i++)
            if (currentState[i] == 'Y')
                result = min(result, minCost(i, bit));
        if (result == INF)
            cout << -1 << endl;
        else
            cout << result << endl;

    }
    return 0;
}
