#include <stdio.h>

int main() {
	int type, prev;

	scanf("%d", &prev);

	if (prev == 1) type = 1;
	else if (prev == 8) type = 2;
	else type = 0;

	for (int i=0 ; i<7 ; i++) {
		int t;

		scanf("%d", &t);

		if (type==1 && t==prev+1);
		else if (type==2 && t==prev-1);
		else type = 0;

		prev = t;
	}

	switch (type) {
	case 1:
		printf("ascending");
		break;

	case 2:
		printf("descending");
		break;

	case 0:
		printf("mixed");
	}

	return 0;
}