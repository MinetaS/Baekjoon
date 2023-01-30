#include <cstdio>
#include <vector>

bool isHan(int);

int main() {
	int n;

	scanf("%d", &n);

	int c = 0;

	for (int t=1 ; t<=n ; t++)
		if (isHan(t)) c++;

	printf("%d", c);

	return 0;
}

bool isHan(int n) {
	if (n < 100) return true;

	std::vector<int> digits;
	int _tmp = n;

	while (_tmp > 0) {
		digits.push_back(_tmp%10);
		_tmp /= 10;
	}

	int d = digits[1]-digits[0];

	for (int i=2 ; i<digits.size() ; i++)
		if (digits[i]-digits[i-1] != d) return false;

	return true;
}