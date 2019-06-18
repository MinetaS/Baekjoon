#include <cstdio>
#include <cmath>
#include <algorithm>

#define PI 3.1415926535897932384626433832795028841971L

using namespace std;

int main() {
	int m, n;
	long double r;
	int x1, y1, x2, y2;
	long double shortest = 99999.9L;

	scanf("%d %d %Lf", &m, &n, &r);
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	
	for (int i=0 ; i<=n ; i++) shortest = min((r/n)*(abs(y1-i)+abs(y2-i))+PI*i*(r/n)*abs(x2-x1)/m, shortest);

	printf("%.8Lf", shortest);

	return 0;
}