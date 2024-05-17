#include "header.h"

vector<int> eratosthenes(int n) {
	vector<bool> checkPrime(n + 1, true);
	checkPrime[0] = checkPrime[1] = false;
	for (int i = 2; i * i <= n; i++) {
		if (checkPrime[i]) {
			for (int j = i * i; j <= n; j+=i) {
				checkPrime[j] = false;
			}
		}
	}
	vector<int> prime;
	for (int i = 0; i < n + 1; i++) {
		if (checkPrime[i]) {
			prime.push_back(i);
		}
	}
	return prime;
}

void noldbach() {
	int n, k;
	cin >> n >> k;
	vector<int> prime = eratosthenes(n);
	int count = 0;
	for (int i = 0; i < prime.size(); i++) {
		for (int j = 1; j < i; j++) {
			if (prime[i] == prime[j] + prime[j - 1] + 1) {
				count++;
			}
		}
	}
	if (count >= k) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}