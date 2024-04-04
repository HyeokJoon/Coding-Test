#include <iostream>
#include <algorithm>
using namespace std;

int num;
void solution() {
	int numOf2 = 0;
	int numOf5 = 0;
	for (int i = 2; i <= num; i *= 2) {
		numOf2 += num / i;
	}
	for (int i = 5; i <= num; i *= 5) {
		numOf5 += num / i;
	}
	cout << min(numOf2, numOf5) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> num;
		solution();
	}
}