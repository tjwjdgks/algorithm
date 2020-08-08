#include <iostream>
#include<string>
#include<vector>
using namespace std;

int solution(string s)
{
    vector<char> stackarry;
    if (s.size() == 0) return 1;
    stackarry.push_back(s[0]);
    for (int i = 1; i < s.size(); i++) {
        if (stackarry.back() == s[i]) stackarry.pop_back();
        else stackarry.push_back(s[i]);
    }
    if (stackarry.empty())return 1;
    else return 0;
}