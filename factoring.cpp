#include "header.h"

void factor() {
	int n;
	string output = "";
	string res = "1 x ";
	while (scanf_s("%i", &n)) {
		while (n % 2 == 0) {
			n = n / 2;
			res += "2 x ";
		}
		for (int i = 3; i <= n; i += 2) {
			while (n % i == 0) {
				n = n / i;
				res += to_string(i) + " x ";
			}
		}
		res.erase(res.size() - 3, 3);
		output += res + "\n";
		res = "1 x ";
	}
	printf("%s", output.c_str());
}