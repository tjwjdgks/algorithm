class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<long> ms;
        for (int i = 0; i < nums.size(); i++) {
            long x = (long)nums[i] - t;
            long y = (long)nums[i] + t;
            auto it = ms.lower_bound(x);
            auto it2 = ms.lower_bound(nums[i]);
            if ((it != ms.end() && *it <= nums[i]) || (it2 != ms.end() && *it2 <= y)) return true;
            ms.insert(nums[i]);
            if (ms.size() > k) {
                auto it = ms.find(nums[i - k]);
                ms.erase(it);
            }
        }
        return false;
    }
};