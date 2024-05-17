#include "header.h"

int findLoopNum(int N) {
	int loopNum = 2;
	int begin = 5 * (loopNum - 1);
	while (begin < N) {
		loopNum *= 2;
		begin = 5 * (loopNum - 1);
	}
	return loopNum / 2;
}

int firstNum(int N) {
	if (N <= 5) {
		return N;
	}
	int loopNum = findLoopNum(N);
	int begin = 5 * (loopNum - 1);
	return (N - 1 - begin) / loopNum + 1;
}

void queueGame() {
	int N;
	cin >> N;
	cout << firstNum(N);
}