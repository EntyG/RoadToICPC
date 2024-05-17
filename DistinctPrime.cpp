#include "header.h"

bool check(int n) {
	int factors = 0;
	if (n % 2 == 0) {
		factors++;
		while (n % 2 == 0) {
			n = n / 2;
		}
	}
	for (int i = 3; i <= n; i += 2) {
		if (n % i == 0) {
			factors++;
			if (factors >= 3) {
				return true;
			}
			while (n % i == 0) {
				n = n / i;
			}
		}
	}
	return false;
}

void distinctPrime() {
	int T;
	cin >> T;
	int maxN = 1000000;
	vector<int> testCase;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		testCase.push_back(n);
	}

	for (int i = 0; i < T; i++) {
		int n = testCase[i];
		if (n == 1) {
			cout << 30 << endl;
		}
		else if (n == 2) {
			cout << 42 << endl;
		}
		else {
			int count = 2;
			int number = 42;
			while (count < n) {
				number++;
				if (check(number)) {
					count++;
				}
			}
			cout << number << endl;
		}
	}
}