#include <cstdio>
#include <algorithm>

int main() {
	int angle[3];
	int check = 0;
	bool reg = true;

	for (int i=0 ; i<3 ; i++) {
		scanf("%d", angle+i);
		check += angle[i];
		if (angle[i] != 60) reg = false;
	}

	if (check != 180) {
		printf("Error");
		return 0;
	}

	if (reg) {
		printf("Equilateral");
		return 0;
	}

	std::sort(angle, angle+3);

	if (angle[0]==angle[1] || angle[1]==angle[2]) {
		printf("Isosceles");
		return 0;
	}

	printf("Scalene");

	return 0;
}