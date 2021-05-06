#include <iostream>
#include <vector>
using namespace std;

// �̺� Ž��

// ������������ ���� �Ǿ��ٰ� ����
// default
int default_search(vector<int> arr, int k) {
    int left = 0;
    int right = arr.size() - 1;
    int answer = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (k == arr[mid]) return k;
        else if (k < arr[mid])
            right = mid - 1;
        else left = mid + 1;
    }
    return answer;
}
//upper bound
// Ű ������ ū ���� ������ ������ ���� �ε���
int upper_bound(vector<int> arr, int k) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= k)
            left = mid + 1;
        else right = mid;
    }
    return left;
}
//lower bound
// Ű �� �̻� ������ ������ ���� �ε���
int lower_bound(vector<int> arr, int k) {
    int left = 0;
    int right = arr.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= k)
            right = mid;
        else left = mid + 1;
    }
    return left;
}
int main() {
   
}