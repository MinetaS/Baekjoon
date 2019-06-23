#include <cstdio>
#include <string>

using namespace std;

int main() {
	int n;
	string s;

	scanf("%d", &n);
	s = to_string(n+1);

	for (char &c : s)
		if (c == 48) c++;

	printf("%s", s.c_str());

	return 0;
}