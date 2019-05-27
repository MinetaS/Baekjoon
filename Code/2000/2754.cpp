#include <stdio.h>

int main() {
	double grade[6] = {4.0, 3.0, 2.0, 1.0, 0.0, -99999};
	double comp[4] = {0.3, 0.0, -0.3, -0.9};
	
	int t, s;
	int c;

	c = getchar();
	t = 5;
	s = 3;

	if (c == 'F') {
		t = 4;
		s = 1;
	}
	else {
		t = c-65;
		c = getchar();
		
		if (c == '+') s = 0;
		if (c == '0') s = 1;
		if (c == '-') s = 2;
	}

	printf("%.1lf", grade[t]+comp[s]);

	return 0;
}