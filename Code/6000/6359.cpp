#include <cstdio>
#include <cstring>

int main() {
	int _case;
	int n, count;
	int cell[100];

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		scanf("%d", &n);
		memset(cell, 0, sizeof(cell));
		count = 0;

		for (int i=1 ; i<=n ; i++)
			for (int j=0 ; j<n ; j++)
				if ((j+1)%i == 0) cell[j]++;

		for (int i=0 ; i<n ; i++)
			if (cell[i] & 0x1) count++;

		printf("%d\n", count);
	}

	return 0;
}