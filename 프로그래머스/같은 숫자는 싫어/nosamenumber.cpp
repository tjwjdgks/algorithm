#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int check = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (i == 0) {
            check = arr[0];
            answer.push_back(check);
        }
        else {
            if (check != arr[i]) {
                check = arr[i];
                answer.push_back(check);
            }
        }

    }
    return answer;
}