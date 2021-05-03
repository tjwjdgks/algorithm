#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;


//�ִ� ���� �κ� ���� ��
// �����ϰ� Ǯ���� �� �˰��� n**2

// ���� ���� �ð� ���⵵ nlogn
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
//���� ��ȹ�� �ð����⵵ N
int fastestMaxSum(const vector<int>& a) {
	int N = a.size(), ret = INT_MIN, psum = 0;
	for (int i = 0; i < N; i++) {
		psum = max(psum, 0) + a[i];
		ret = max(ret, psum);
	}
	return ret;
}
/* �ð����⵵ 1�� ����
   N**3 input 2560����
   N**2 input 40960����
   NlogN input 2õ�� ����
   N input 1�� 6õ�� ����
*/

/*
���缺 ����

�ݺ��� �Һ���
1. �ݺ��� ���Խÿ� �Һ��� ����
2. �ݺ��� ������ �Һ����� ���߸��� ����, ������ ���� �� ���� �Һ��� ����
3. �ݺ��� ����ÿ� �Һ����� �����ϸ� �׻� �츮�� ������ �������� ����

����Ž���� �ݺ��� �Һ���
�������İ� �ݺ��� �Һ���

�������� �̿��� �ݺ��� �Һ��� �����ϱ�
*/
/*
�ͷ���
*/
//

//��Ÿ�� �߶󳻱� ����
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
//ī�������� ���� ���� ���� �˰���
// a+= b*(10^k)�� ����
void addTo(vector<int>& a, const vector<int>& b, int k) {

}
// a-= b �� ���� a >=b�� ����
void subFrom(vector<int>& a, const vector<int>& b) {

}
// ����
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