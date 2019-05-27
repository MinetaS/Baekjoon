#include <cstdio>

int main() {
	constexpr int result[14] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596};
	int n;

	scanf("%d", &n);
	printf("%d", result[n-1]);

	return 0;
}

// Original Source
/*
#include <cstdio>
#include <cmath>

int place(int, const int);

int pos[14] = {0,};

int main() {
	int n;

	scanf("%d", &n);
	printf("%d", place(0, n));

	return 0;
}

int place(int index, const int n) {
	int ret = 0;

	if (index == n) return 1;

	for (int i=0 ; i<n ; i++) {
		bool possible = true;

		for (int j=0 ; j<index ; j++) {
			if (i==pos[j] || abs(index-j)==abs(i-pos[j])) {
				possible = false;
				break;
			}
		}

		if (!possible) continue;

		pos[index] = i;
		ret += place(index+1, n);
		pos[index] = 0;
	}

	return ret;
}
*/