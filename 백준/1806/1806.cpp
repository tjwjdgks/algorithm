#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];
int N, S;

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	int high = 0;
	int low = 0;
	int length = 987654321;
	int sum = arr[0];
	while (low <= high && high < N) {
		if (sum < S) {
			sum += arr[++high];
		}
		else if (sum == S) {
			length = min(length, high - low + 1);
			sum += arr[++high];
		}
		else {
			length = min(length, high - low + 1);
			sum -= arr[low++];
		}
	}
	if (length == 987654321)
		cout << 0;
	else
		cout << length;
}