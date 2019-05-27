#include <cstdio>
#include <cstring>

int num[30001];
int cache[30001];

int main() {
	int _case;

	scanf("%d", &_case);

	while (_case > 0) {
		_case--;

		int n;

		scanf("%d", &n);
		for (int i=0 ; i<n ; i++)
			scanf("%d", num+i);

		memset(cache, 0, sizeof(cache));
		cache[1] = num[0];

		for (int i=1 ; i<n ; i++) {
			if (num[i] > cache[1]) cache[1] = num[i];

			for (int j=1 ; cache[j]!=0 ; j++) {
				if (j & 0x1) {
					if (num[i] < cache[j])
						if (cache[j+1]==0 || num[i]<cache[j+1]) cache[j+1] = num[i];
				}
				else if (num[i] > cache[j])
						if (cache[j+1]==0 || num[i]>cache[j+1]) cache[j+1] = num[i];
			}
		}

		int r;
		for(r=1 ; cache[r]!=0 ; r++);

		printf("%d\n", r-1);
	}

	return 0;
}