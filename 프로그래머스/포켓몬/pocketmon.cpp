#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> arry;
    for (int i = 0; i < nums.size(); i++) {
        if (arry.find(nums[i]) == arry.end()) arry.insert(nums[i]);
    }
    if (arry.size() >= nums.size() / 2) answer = nums.size() / 2;
    else answer = arry.size();
    return answer;
}