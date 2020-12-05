#include <iostream>
#include <vector>
using namespace std;


int W, maxprofit, numbest;
// -1 해당 x, 0 = 값 선택, 1 = 값 선택 안함
vector<string> include;
vector<string> bestset;
vector<int> p;
vector<int> w;
int n;

bool promising(int i, int weight, int profit);

void knapsack(int i, int profit, int weight) {
	if (weight <= W && profit > maxprofit) {
		maxprofit = profit;
		numbest = i;
		bestset = include;
	}
	if (promising(i, weight, profit)) {
		include[i + 1] = "yes";
		knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
		include[i + 1] = "no";
		knapsack(i + 1, profit, weight);
	}
}
bool promising(int i, int weight, int profit) {
	int j, k;
	int totweight;
	float bound;
	if (weight >= W)
		return false;
	else {
		j = i + 1;
		bound = profit;
		totweight = weight;
		while (j <= n && totweight + w[j] <= W) {
			totweight = totweight + w[j];
			bound = bound + p[j];
			j++;
		}
		k = j;
		if (k <= n)
			bound = bound + (W - totweight) * p[k] / w[k];

		return bound > maxprofit;
	}
}




int main() {
	numbest = 0;
	maxprofit = 0;
	W = 16;
	n = 4;

	include.resize(n + 1, "");
	p = { 0,40,30,50,10 };
	w = { 0,2,5,10,5 };
	knapsack(0, 0, 0);
	cout << maxprofit << endl;
	for (int j = 1; j <= numbest; j++)
		cout << bestset[j] << " ";
}