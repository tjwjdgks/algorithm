#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int lo = 0;
        int hi = nums[nums.size() - 1] - nums[0];
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            int count = 0, left = 0;
            for (int right = 0; right < nums.size(); right++) {
                while (nums[right] - nums[left] > mid) left++;
                count += right - left;
            }
            if (count >= k) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
// k 이상
int lower_bound(vector<int> array, int k) {
    int lo = 0;
    int hi = array.size();
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (array[mid] >= k)
            hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
//k 초과
int upper_bound(vector<int> array, int k) {
    int lo = 0;
    int hi = array.size();
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (array[mid] <= k)
            lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
int main() {
 
}