#include "header.h"

struct cus {
	int k, p;

	cus(int k, int p) :k(k), p(p) {};
};

struct cmp {
	bool operator() (cus a, cus b) {
		return a.p < b.p;
	}
};

void bigBank() {
	string outPut = "";
	priority_queue<cus, vector<cus>, cmp> st2, st3;
	unordered_set<int> removed;
	while (true) {
		int choice;
		cin >> choice;
		if (!choice) {
			outPut.erase(outPut.size() - 1);
			cout << outPut;
			return;		
		}
		switch (choice)
		{
		case 1:
			int k, p;
			cin >> k >> p;
			st2.push(cus(k, p));
			st3.push(cus(k, -p));
			break;
		case 2:
			while (!st2.empty() && removed.find(st2.top().k) != removed.end()) {
				st2.pop();
			}
			if (st2.empty()) {
				outPut += "0\n";
			}
			else {
				outPut += to_string(st2.top().k) + "\n";
				removed.insert(st2.top().k);
				st2.pop();
			}
			break;
		case 3:
			while (!st3.empty() && removed.find(st3.top().k) != removed.end()) {
				st3.pop();
			}

			if (st3.empty()) {
				outPut += "0\n";
			}
			else {
				outPut += to_string(st3.top().k) + "\n";
				removed.insert(st3.top().k);
				st3.pop();
			}
			break;
		default:
			break;
		}
	}
}
