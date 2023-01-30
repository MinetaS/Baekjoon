#include <cstdio>
#include <vector>

int main() {
	int n, k;
	std::vector<int> num;

	scanf("%d %d", &n, &k);

	for (int i=0 ; i<n ; i++) {
		int t;

		if (i == n-1) scanf("%d", &t);
		else scanf("%d,", &t);

		num.push_back(t);
	}

	for (int i=0 ; i<k ; i++) {
		int size = num.size();

		for (int j=0 ; j<size-1 ; j++)
			num.push_back(num[j+1]-num[j]);

		for (int j=0 ; j<size ; j++)
			num.erase(num.begin());
	}

	for (int i=0 ; i<num.size() ; i++) {
		printf("%d", num[i]);
		if (i != num.size()-1) printf(",");
	}

	return 0;
}