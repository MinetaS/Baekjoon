#include <cstdio>

long long dance(int, int);

int main() {
	int n;

	scanf("%d", &n);
	printf("%lld", dance(1, n));

	return 0;
}

long long dance(int _Left, int _Right) {
	if (_Left == _Right) return 0;
	if (_Right-_Left == 1) return _Left*_Right;
	if (_Right-_Left > 1) return dance(_Left, _Left+(_Right-_Left)/2) + dance(_Left+(_Right-_Left)/2+1, _Right);
}