#include <cstdio>

int main() {
	int n, t;
	int cute[2] = {0,};

	scanf("%d", &n);

	for (int i=0 ; i<n ; i++) {
		scanf("%d", &t);
		cute[t]++;
	}

	if (cute[0] > cute[1]) printf("Junhee is not cute!");
	else printf("Junhee is cute!");

	return 0;
}