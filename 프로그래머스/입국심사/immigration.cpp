#include <string>
#include <vector>
#include <algorithm>
using namespace std;
long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long sum = 0;
	sort(times.begin(), times.end());
	long long min = 1;
	long long max = (long long)times.back() * n;
	long long mid = (max + min) / 2;
	answer = max;
	while (min <= max) {
		sum = 0;
		mid = (max + min) / 2;
		for (int i = 0; i < times.size(); i++) {
			sum += mid / times[i];
		}
		if (sum < n) min = mid + 1;
		else {
			if (mid <= answer)
				answer = mid;
			max = mid - 1;
		}
	}
	return answer;
}