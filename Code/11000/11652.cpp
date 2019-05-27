#include <cstdio>

typedef long long int64_t;

int64_t appeared[1000000];
int count[1000000];

int main() {
	int n;
	int size = 0;

	int freq = 1;
	int64_t min = 9223372036854775807ll;

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		int64_t t;
		bool new_ap = true;
		int index;

		scanf("%lld", &t);

		for (int l=0 ; l<size ; l++) {
			if (appeared[l] == t) {
				new_ap = false;
				index = l;
				break;
			}
		}

		if (new_ap) {
			appeared[size] = t;
			count[size] = 1;
			index = size++;
		}
		else count[index]++;

		if (count[index] == freq)
			if (t < min) min = t;
		
		if (count[index] > freq) {
			freq = count[index];
			min = t;
		}
	}

	printf("%lld", min);

	return 0;
}