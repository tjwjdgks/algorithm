#include<iostream>
using namespace std;

int getCntNum1(int n)
{
    int nCnt = 0;
    for (int i = 0; i < 31; i++)
    {
        if (n & 0x01 << i)
            nCnt++;
    }
    return nCnt;
}

int nextBigNumber(int n)
{
    int nNum1Cnt = getCntNum1(n);

    while (1)
    {
        n++;
        if (nNum1Cnt == getCntNum1(n))
            return n;
    }
}