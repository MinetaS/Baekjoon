#include <cstdio>
#include <string>

using namespace std;

int main() {
	int n, m;

	scanf("%d %d", &n, &m);
	string str = to_string(n);
	int l = str.size();

	for (int i=0 ; i<min(m, n*l) ; i++)
		printf("%c", str[i%l]);

	return 0;
}