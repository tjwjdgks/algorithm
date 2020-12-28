#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int N;
int dpl[1001];
int dpr[1001];
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr[i] = -temp;
	}
	for (int i = 0; i < N; i++) {
		dpl[i] = 1;
		dpr[N - i - 1] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dpl[j] + 1 > dpl[i]) dpl[i] = dpl[j] + 1;
			if (arr[N - i - 1] > arr[N - j - 1] && dpr[N - j - 1] + 1 > dpr[N - i - 1]) dpr[N - i - 1] = dpr[N - j - 1] + 1;

		}
	}
	int maxinum = 0;
	for (int i = 0; i < N; i++) {
		maxinum = max(maxinum, dpl[i] + dpr[i] - 1);
	}
	cout << maxinum;
}