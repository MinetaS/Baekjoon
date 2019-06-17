#include <cstdio>
#include <string>

using namespace std;

int main() {
	int n;
	string s1 = "";
	string s2 = "";

	scanf("%d", &n);

	for (int i=0 ; i<n/2 ; i++) {
		s1 += "Aa";
		s2 += "BB";
	}

	if (n & 1) {
		s1 += "X";
		s2 += "X";
	}

	printf("%s\n%s", s1.c_str(), s2.c_str());

	return 0;
}