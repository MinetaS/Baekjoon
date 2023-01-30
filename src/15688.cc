#include <cstdio>
#include <cstring>

int count[2000001] = {0,};

int main() {
	int n;

	scanf("%d", &n);

	for (int t, i=0 ; i<n ; i++) {
		scanf("%d", &t);
		count[t+1000000]++;
	}

	for (int i=0 ; i<2000001 ; i++)
		for (int j=0 ; j<count[i] ; j++) printf("%d\n", i-1000000);

	return 0;
}