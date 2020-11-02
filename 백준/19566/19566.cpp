#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	long long N, K;
	cin >> N >> K;
	map<long long, long long > m;
	long long s = 0;
	long long temptotal = 0;
	long long count = 0;
	for (long long i = 0; i < N; i++) {
		long long tempnum;
		cin >> tempnum;
		s += tempnum;
		temptotal = s - K * (i + 1);
		count += m[temptotal];
		m[temptotal]++;
	}
	cout << count + m[0];
}