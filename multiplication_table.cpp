#include <iostream>
using namespace std;

/*
mid is the potential median to check.
mid/i gives us the number of numbers in a row that are less than mid. (experiment and see)
basically we need the (n^2+1)/2 smallest element-> will be the median. so if number of numbers less than mid are greater 
than or equal to this, it may be a median and we narrow the range accordingly. else, increase low
*/

int main() {
	long long n;
	cin >> n;
	long long low = 1, high = n * n, mid, leq;

	// binary search to get the median
	while (low < high) {
		mid = (low + high) / 2;
		leq = 0;
		for (int i = 1; i <= n; i++) { leq += min(n, mid / i); }
		if (leq >= (n * n + 1) / 2) {
			high = mid;
		} else {
			low = mid + 1;
		}
	}
	cout << high << endl;
	return 0;
}