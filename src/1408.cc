#include <cstdio>

int main() {
	int h1, m1, s1, t1;
	int h2, m2, s2, t2;
	int res, h3, m3, s3;

	scanf("%d:%d:%d", &h1, &m1, &s1);
	scanf("%d:%d:%d", &h2, &m2, &s2);

	t1 = h1*3600+m1*60+s1;
	t2 = h2*3600+m2*60+s2;

	res = t2-t1;
	if (res < 0) res += 86400;

	h3 = res/3600;
	m3 = (res-h3*3600)/60;
	s3 = res%60;

	printf("%02d:%02d:%02d", h3, m3, s3);

	return 0;
}