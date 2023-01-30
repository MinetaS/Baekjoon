#include <cstdio>

int main() {
	int s1, s2, s3;
	int res[80] = {0,};

	scanf("%d %d %d", &s1, &s2, &s3);

	for (int i=1 ; i<=s1 ; i++)
		for (int j=1 ; j<=s2 ; j++)
			for (int k=1 ; k<=s3 ; k++)
				res[i+j+k-1]++;

	int max_value = 0;
	int max_num = -1;

	for (int i=0 ; i<s1+s2+s3 ; i++) {
		if (res[i] > max_value) {
			max_value = res[i];
			max_num = i+1;
		}
	}

	printf("%d", max_num);

	return 0;
}