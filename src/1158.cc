#include <cstdio>
#include <vector>

using namespace std;

int main() {
	int n, k;
	int index, size, count;
	vector<int> left;

	scanf("%d %d", &n, &k);

	size = n;
	left.reserve(n);

	for (int i=0 ; i<n ; i++)
		left.push_back(i+1);

	printf("<");
	count = 0;
	index = -1;
	
	while (size > 0) {
		index = (index+1)%n;

		if (left[index] == 0) continue;
		count++;
		
		if (count == k) {
			if (size == 1) printf("%d", left[index]);
			else printf("%d, ", left[index]);

			left[index] = 0;
			count = 0;
			size--;
		}
	}

	printf(">");

	return 0;
}