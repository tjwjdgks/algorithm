#include <algorithm>
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        vector<int> first(n + 1, 0);
        vector<int> last(n + 1, 0);
        for (int i = 0; i < cardPoints.size(); i++) {
            first[i + 1] = cardPoints[i] + first[i];
            last[i + 1] = cardPoints[n - i - 1] + last[i];
        }
        int maxnum = 0;
        for (int i = 0; i <= k; i++) {
            int curnum = first[i] + last[k - i];
            maxnum = max(maxnum, curnum);
        }
        return maxnum;
    }
};