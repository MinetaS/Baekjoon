#include <cstdio>
#include <string>

using namespace std;

int main() {
	char a[9], b[9];
	string s;
	string s_new;

	scanf("%s\n%s", a, b);

	for (int i=0 ; i<8 ; i++) {
		s.push_back(a[i]);
		s.push_back(b[i]);
	}

	s_new = s;

	while (true) {
		if (s_new.length() <= 2) break;

		s = s_new;
		s_new.clear();

		for (int i=0 ; i<s.size()-1 ; i++)
			s_new.push_back((s[i]+s[i+1]-96)%10+48);
	}

	printf("%02d", stoi(s_new));

	return 0;
}