#include <vector>
#include <algorithm>
class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int> maxleft(A.size(), 0);
        vector<int> minright(A.size(), 0);
        int m = A[0];
        for (int i = 0; i < A.size(); i++) {
            m = max(m, A[i]);
            maxleft[i] = m;
        }
        m = A[A.size() - 1];
        for (int i = A.size() - 1; i >= 0; i--) {
            m = min(m, A[i]);
            minright[i] = m;
        }
        for (int i = 1; i < A.size(); i++) {
            if (maxleft[i - 1] <= minright[i])
                return i;
        }
        return 0;
    }
};