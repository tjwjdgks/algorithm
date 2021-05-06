#include <iostream>
#include <vector>
using namespace std;

// 이분 탐색

// 오름차순으로 정렬 되었다고 가정
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
// 키 값보다 큰 값이 나오는 최초의 지점 인덱스
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
// 키 값 이상 나오는 최초의 지점 인덱스
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