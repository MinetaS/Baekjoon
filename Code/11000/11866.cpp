#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n, k;
	vector<int> set;

	scanf("%d %d", &n, &k);
	set.reserve(n);

	for (int i=0 ; i<n ; i++) set.push_back(i+1);

	printf("<");

	for (int i=k-1 ; ; ) {
		vector<int>::iterator it = set.begin()+i;

		printf("%d", *it);
		if (set.size() != 1) printf(", ");

		set.erase(it);
		if (set.empty()) break;

		i = (i+k-1)%set.size();
	}
	
	printf(">");

	return 0;
}