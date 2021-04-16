#include <iostream>
using namespace std;

int P;
long long pisano(long long m) {
	long long f0 = 0, f1 = 1, f2 = f0 + f1;
	for (long long i = 0; i < m * m; i++) {
		f2 = (f0 + f1) % m;
		f0 = f1;
		f1 = f2;
		if (f0 == 0 && f1 == 1) return i + 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> P;
	for (int i = 0; i < P; i++) {
		int tempN, tempM;
		cin >> tempN >> tempM;
		cout << tempN << " " <<  pisano(tempM) << '\n';
	}
}