#include <cstdio>

int main() {
	long double pab, pbc, pcd;

	scanf("%Lf %Lf %Lf", &pab, &pbc, &pcd);
	printf("%Lf", pab*pcd/pbc);

	return 0;
}