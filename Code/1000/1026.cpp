#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int N;
	int A[50], B[50];

	scanf("%d", &N);

	for (int i=0 ; i<N ; i++)
		scanf("%d", &A[i]);

	for (int i=0 ; i<N ; i++)
		scanf("%d", &B[i]);

	sort(A, A+N);
	sort(B, B+N, greater<int>());

	int s = 0;

	for (int i=0 ; i<N ; i++)
		s += A[i]*B[i];

	printf("%d", s);

	return 0;
}	