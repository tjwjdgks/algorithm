#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;


//최대 연속 부분 구간 합
// 무식하게 풀었을 때 알고리즘 n**2

// 분할 정복 시간 복잡도 nlogn
int fastestMaxSum(const vector<int>& a, int lo, int hi) {
	if (lo == hi) return a[lo];
	int mid = (lo + hi) / 2;
	int right = INT_MIN, left = INT_MIN;
	int sum = 0;
	for (int i = mid; i >= lo; i--) {
		sum += a[i];
		left = max(left, sum);
	}
	sum = 0;
	for (int i = mid + 1; i <= hi; i++) {
		sum += a[i];
		right = max(right, sum);
	}
	int single = max(fastestMaxSum(a, lo, mid), fastestMaxSum(a, mid + 1, hi));
	return max(left + right, single);
}
//동적 계획법 시간복잡도 N
int fastestMaxSum(const vector<int>& a) {
	int N = a.size(), ret = INT_MIN, psum = 0;
	for (int i = 0; i < N; i++) {
		psum = max(psum, 0) + a[i];
		ret = max(ret, psum);
	}
	return ret;
}
/* 시간복잡도 1초 기준
   N**3 input 2560까지
   N**2 input 40960까지
   NlogN input 2천만 까지
   N input 1억 6천만 까지
*/

/*
정당성 증명

반복문 불변식
1. 반복문 진입시에 불변식 성립
2. 반복문 내용이 불변식을 깨뜨리지 않음, 내용이 끝날 때 까지 불변식 성립
3. 반복문 종료시에 불변식이 성립하면 항상 우리는 정답을 구했음을 보임

이진탐색과 반복문 불변식
삽입정렬과 반복문 불변식

단정문을 이용해 반복문 불변식 강제하기
*/
/*
귀류법
*/
//

//울타리 잘라내기 문제
vector<int> h;
int solve(int left, int right) {
	if (left == right) return h[right];
	int mid = (left + right) / 2;
	int ret = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);
	ret = max(ret, height * 2);
	while (left < lo || hi < right) {
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
			++hi;
			height = min(height, h[hi]);
		}
		else {
			--lo;
			height = min(height, h[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}
//카라츠바의 빠른 정수 곱셈 알고리즘
// a+= b*(10^k)를 구현
void addTo(vector<int>& a, const vector<int>& b, int k) {

}
// a-= b 를 구현 a >=b를 가정
void subFrom(vector<int>& a, const vector<int>& b) {

}
// 곱셈
vector<int> multiply(vector<int> a, vector<int> b) {
	vector<int> answer;
	return answer;
}
vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
	int an = a.size(), bn = b.size();
	if (an < bn) return karatsuba(b, a);

	if (an == 0 || bn == 0) return vector<int>();

	if (an <= 50) return multiply(a, b);
	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin()+half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half),b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0); addTo(b0, b1, 0);
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;


}
int main() {

}