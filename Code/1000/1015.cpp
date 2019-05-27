#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int A[50];
	int B[50];
	int P[50];
	int checked[50];
	int t;

	scanf("%d", &N);
	for (int i=0 ; i<N ; i++) {
		scanf("%d", &t);
		A[i] = t;
		B[i] = t;
		checked[i] = 0;
	}

	sort(B, B+N);

	for (int i=0 ; i<N ; i++) {
		for (int j=0 ; j<N ; j++) {
			if (A[i] == B[j]) {
				if (checked[j] == 1) continue;
				P[i] = j;
				checked[j] = 1;
				break;
			}
		}
	}

	for (int i=0 ; i<N ; i++)
		printf("%d ", P[i]);

	return 0;
}