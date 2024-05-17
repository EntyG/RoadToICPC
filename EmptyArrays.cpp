#include "header.h"

void emptyArrays() {
	int T = 0;
	int n;
	cin >> n;
	int* a = new int[n + 1];
	int* b = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[n] = -1;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	int* ptr = a;
	
	for (int i = 0; i < n; i++) {
		while (ptr[0] != b[i]) {
			ptr++;
			T++;
			if (ptr[0] == -1) {
				ptr = a;
			}
		}
		T++;
		for (int i = 0; ptr[i] != -1; i++) {
			ptr[i] = ptr[i + 1];
		}
		if (ptr[0] == -1) {
			ptr = a;
		}
	}
	cout << T;
	delete[] a;
	delete[] b;
}