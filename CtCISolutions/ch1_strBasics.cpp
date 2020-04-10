#include <iostream>
#include <vector>
using namespace std;

void ch1_test0() {
	int img[4][4] = { {0,0,0,0}, {1,1,1,1}, {2,2,2,2}, {3,3,3,3} };
	std::cout << "." << 'A' % 128 << "." << std::endl;

	std::vector<int> v1(5, 1); //vector with 5 items, all of them are 1,
	for (int i : v1) {
		std::cout << i << ",";
	}
	std::cout << std::endl;
}

bool isStringRotation(const string& s1, const string& s2) {
	if (s1.length() != s2.length()) return false;
	const int PIVOT_INDEX = 3;
	string x = s1.substr(0, PIVOT_INDEX);
	string y = s1.substr(PIVOT_INDEX, s1.length() - PIVOT_INDEX);
	cout << "x:" << x << ",y:" << y << std::endl;
	return true;
}

bool isSubstring(string s1, string s2) {
	return true;
}
