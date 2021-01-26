#include <iostream>

int Countnum(int num) {
	int count = 0;
	int a[3] = { 0, };
	if (num / 100 == 0) {
		count = num;
	}
	else {
		for (int i = 100; i <= num; i++) {
			a[0] = i / 100;
			a[1] = (i % 100) / 10;
			a[2] = i % 10;
			if (a[0] - a[1] == a[1] - a[2]) {
				count = count + 1;
			}
		}
		count = count + 99;
	}
	return count;
}
int main()
{
	int a, b;
	std::cin >> a;
	b = Countnum(a);
	std::cout << b;
}
