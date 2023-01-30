#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	bool yu = false;

	cin >> str;

	int size = str.length();

	for (int i=0 ; i<size-1 ; i++) {
		int part1 = 1;
		int part2 = 1;

		for (int j=0 ; j<=i ; j++)
			part1 *= str[j]-48;

		for (int j=i+1 ; j<size ; j++)
			part2 *= str[j]-48;

		if (part1 == part2) {
			yu = true;
			break;
		}
	}

	if (yu) printf("YES");
	else printf("NO");

	return 0;
}