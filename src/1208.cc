#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef unsigned long long uint64;

int main() {
	int n, s;

	scanf("%d %d", &n, &s);

	int half = n/2;
	int first_size = 1<<half;
	int second_size = 1<<(n-half);
	vector<int> num = vector<int>(n);
	vector<int> first = vector<int>(first_size);
	vector<int> second = vector<int>(second_size);

	for (int i=0 ; i<n ; i++)
		scanf("%d", &num[i]);

	for (int i=0 ; i<first_size ; i++)
		for (int j=0 ; j<half ; j++)
			if ((i & (1<<j)) != 0) first[i] += num[j];

	for (int i=0 ; i<second_size ; i++)
		for (int j=0 ; j<n-half ; j++)
			if ((i & (1<<j)) != 0) second[i] += num[half+j];

	sort(first.begin(), first.end());
	sort(second.begin(), second.end(), greater<int>());

	uint64 count = 0;
	int index1 = 0;
	int index2 = 0;

	while (true) {
		if (index1>=first_size || index2>=second_size) break;

		if (first[index1]+second[index2] == s) {
			uint64 dup1 = 1;
			uint64 dup2 = 1;

			index1++;
			index2++;

			while (index1<first_size && first[index1]==first[index1-1]) {
				index1++;
				dup1++;
			}

			while (index2<second_size && second[index2]==second[index2-1]) {
				index2++;
				dup2++;
			}

			count += dup1*dup2;
		}

		else if (first[index1]+second[index2] > s) index2++;
		else if (first[index1]+second[index2] < s) index1++;
	}

	if (s == 0) count--;

	printf("%llu", count);

	return 0;
}